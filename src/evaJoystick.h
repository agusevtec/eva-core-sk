#ifndef EVAJOYSTICK_H_
#define EVAJOYSTICK_H_
#include "evaStdReaders.h"

namespace eva
{
  /**
   * @brief Joystick axis reader (range 1000-1500-2000) with trim adjustment
   * @tparam READER Underlying reader type
   * @tparam MIN_POS Minimum analog value
   * @tparam MIDDLE_POS Center value
   * @tparam MAX_POS Maximum analog value
   */
  template <class READER, int MIN_POS, int MIDDLE_POS, int MAX_POS>
  class Joystick : public READER
  {
  public:
    /**
     * @brief Gets normalized joystick position (1000 to 2000)
     * @return Signed char value
     */
    signed short getValue()
    {
      signed short value = READER::getValue();
      if ((value < MIDDLE_POS) ^ (MIN_POS < MAX_POS))
        return constrain(map(value, MIDDLE_POS, MAX_POS, 1500 + this->trim - this->deadZone, 2000), 1500 + this->trim, 2000);
      else
        return constrain(map(value, MIN_POS, MIDDLE_POS, 1000, 1500 + this->trim + this->deadZone), 1000, 1500 + this->trim);
    }

    /**
     * @brief Sets trim adjustment value
     * @param trim Trim value
     */
    void setTrim(short trim)
    {
      this->trim = constrain(trim, -127, 127);
    }

    /**
     * @brief adds trim adjustment value
     * @param trim Trim value
     */
    void addTrim(short trimIncrement)
    {
      this->trim = constrain(this->trim + trimIncrement, -127, 127);
    }

    /**
     * @brief Gets current trim value
     * @return deadZone value
     */
    signed short getTrim()
    {
      return this->trim;
    }

    void setDeadZone(short deadZone)
    {
      this->deadZone = constrain(deadZone, 0, 255);
    }


    /**
     * @brief Gets current deadZone value
     * @return deadZone value
     */
    signed short getDeadZone()
    {
      return this->deadZone;
    }

  private:
    signed char trim = 0;
    unsigned char deadZone = 0;
  };
  /**
   * @brief Pin-based joystick with symmetric range (MIN_POS to MAX_POS, center at midpoint)
   * @tparam PIN Arduino pin number
   * @tparam PIN_MODE Pin mode (usually INPUT)
   * @tparam MIN_POS Minimum analog reading
   * @tparam MAX_POS Maximum analog reading
   */
  template <int PIN, int PIN_MODE, int MIN_POS, int MAX_POS>
  using PinSymmetricJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, (MAX_POS - MIN_POS) / 2, MAX_POS>;
  /**
   * @brief Pin-based joystick with custom center position
   * @tparam PIN Arduino pin number
   * @tparam PIN_MODE Pin mode (usually INPUT)
   * @tparam MIN_POS Minimum analog reading
   * @tparam MIDDLE_POS Center position reading
   * @tparam MAX_POS Maximum analog reading
   */
  template <int PIN, int PIN_MODE, int MIN_POS, int MIDDLE_POS, int MAX_POS>
  using PinJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, MIDDLE_POS, MAX_POS>;
};

#endif
