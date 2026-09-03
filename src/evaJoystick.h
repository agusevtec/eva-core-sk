#pragma once

#include "evaStdReaders.h"

namespace eva
{
  /**
   * @brief Joystick axis reader (range 1000-1500-2000) with trim adjustment
   * @param deadZone dead-zone value
   * @tparam TReader Underlying reader type
   * @tparam tMinPos Minimum analog value
   * @tparam tMiddlePos Center value
   * @tparam tMaxPos Maximum analog value
   */
  template <class TReader, unsigned short tMinPos = 0, unsigned short tMiddlePos = 512, unsigned short tMaxPos = 1024>
  class Joystick : public TReader
  {
  public:
    /**
     * @brief Constructs a Joystick with optional dead zone
     * @param aDeadZone Dead-zone value (0-255)
     * @param args Additional arguments passed to TReader constructor
     */
    template <typename... Args>
    Joystick(short aDeadZone = 0, Args... args) : TReader(args...) , trim(0)
    {
       setDeadZone(aDeadZone);
    }

    /**
     * @brief Gets normalized joystick position with custom ranges
     * @param aMinPos Minimum analog value
     * @param aMiddlePos Center analog value
     * @param aMaxPos Maximum analog value
     * @return Value from 1000 to 2000
     */
    signed short getValue(unsigned short aMinPos, unsigned short aMiddlePos, unsigned short aMaxPos)
    {
      signed short value = TReader::getValue();
      if ((value < aMiddlePos) ^ (aMinPos < aMaxPos))
        return constrain(map(value, aMiddlePos, aMaxPos, 1500 + this->trim - this->deadZone, 2000), 1500 + this->trim, 2000);
      else
        return constrain(map(value, aMinPos, aMiddlePos, 1000, 1500 + this->trim + this->deadZone), 1000, 1500 + this->trim);
    }

    /**
     * @brief Gets normalized joystick position (1000 to 2000)
     * @return Value from 1000 to 2000
     */
    signed short getValue()
    {
      return getValue(tMinPos, tMiddlePos, tMaxPos);
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
     * @param trim value
     */
    void addTrim(short trimIncrement)
    {
      this->trim = constrain(this->trim + trimIncrement, -127, 127);
    }

    /**
     * @brief Gets current trim value
     * @return trim value
     */
    signed short getTrim()
    {
      return this->trim;
    }

    /**
     * @brief Sets dead-zone value
     * @param deadZone dead-zone value
     */
    void setDeadZone(short deadZone)
    {
      this->deadZone = constrain(deadZone, 0, 255);
    }

    /**
     * @brief Gets current dead-zone value
     * @return deadZone value
     */
    signed short getDeadZone()
    {
      return this->deadZone;
    }

  private:
    signed char trim;
    unsigned char deadZone;
  };

  /**
   * @brief Pin-based joystick with symmetric range (tMinPos to tMaxPos, center at midpoint)
   * @tparam tPin Arduino pin number
   * @tparam tPinMode Pin mode (usually INPUT)
   * @tparam tMinPos Minimum analog reading
   * @tparam tMaxPos Maximum analog reading
   */
  template <int tPin, int tPinMode, unsigned short tMinPos, unsigned short tMaxPos>
  using PinSymmetricJoystick = Joystick<AnalogPinReader<tPin, tPinMode>, tMinPos, (tMaxPos + tMinPos) / 2, tMaxPos>;
  /**
   * @brief Pin-based joystick with custom center position
   * @tparam tPin Arduino pin number
   * @tparam tPinMode Pin mode (usually INPUT)
   * @tparam tMinPos Minimum analog reading
   * @tparam tMiddlePos Center position reading
   * @tparam tMaxPos Maximum analog reading
   */
  template <int tPin, int tPinMode, unsigned short tMinPos, unsigned short tMiddlePos, unsigned short tMaxPos>
  using PinJoystick = Joystick<AnalogPinReader<tPin, tPinMode>, tMinPos, tMiddlePos, tMaxPos>;
};
