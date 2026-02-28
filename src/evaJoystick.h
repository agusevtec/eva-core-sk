#ifndef EVAJOYSTICK_H_
#define EVAJOYSTICK_H_
#include "evaStdReaders.h"

namespace eva
{
  /**
   * @brief Joystick axis reader with trim adjustment
   * @tparam READER Underlying reader type
   * @tparam MIN Minimum analog value
   * @tparam MIDDLE Center value
   * @tparam MAX Maximum analog value
   */
  template <class READER, int MIN, int MIDDLE, int MAX>
  class Joystick : public READER
  {
  public:
    /**
     * @brief Gets normalized joystick position (-127 to 127)
     * @return Signed char value
     */
    signed char getValue()
    {
      signed short value = READER::getValue();
      if (SIGN(MIDDLE - value) * SIGN(MAX - MIN) >= 0)
        return constrain(map(value, MIN, MIDDLE, -127, this->trim), -127, this->trim);
      else
        return constrain(map(value, MIDDLE, MAX, this->trim, 127), this->trim, 127);
    }

    /**
     * @brief Sets trim adjustment value
     * @param trim Trim value
     */
    void setTrim(short trim)
    {
      this->trim = trim;
    }

    /**
     * @brief Gets current trim value
     * @return Trim value
     */
    signed short getTrim()
    {
      return this->trim;
    }

  private:
    signed short trim;
  };
  /**
   * @brief Pin-based joystick with symmetric range (MIN to MAX, center at midpoint)
   * @tparam PIN Arduino pin number
   * @tparam PIN_MODE Pin mode (usually INPUT)
   * @tparam MIN Minimum analog reading
   * @tparam MAX Maximum analog reading
   */
  template <int PIN, int PIN_MODE, int MIN, int MAX>
  using PinJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN, (MAX - MIN) / 2, MAX>;
  /**
   * @brief Pin-based joystick with custom center position
   * @tparam PIN Arduino pin number
   * @tparam PIN_MODE Pin mode (usually INPUT)
   * @tparam MIN Minimum analog reading
   * @tparam MIDDLE Center position reading
   * @tparam MAX Maximum analog reading
   */
  template <int PIN, int PIN_MODE, int MIN, int MIDDLE, int MAX>
  using PinJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN, MIDDLE, MAX>;
};

#endif
