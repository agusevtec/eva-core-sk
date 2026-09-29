

# File evaJoystick.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaJoystick.h**](eva_joystick_8h.md)

[Go to the documentation of this file](eva_joystick_8h.md)


```C++
#pragma once

#include "evaStdReaders.h"

namespace eva
{
  template <class TReader, signed short tMinPos = 0, signed short tMiddlePos = 512, signed short tMaxPos = 1024>
  class Joystick : public TReader
  {
  public:
    Joystick() : trim(0), deadZone(0)
    {
    }

    template <typename... Args>
    Joystick(unsigned char aDeadZone, Args... args) : TReader(args...) , trim(0), deadZone(aDeadZone)
    {
    }

    signed short getValue(signed short aMinPos, signed short aMiddlePos, signed short aMaxPos)
    {
      signed short value = TReader::getValue();
      if ((value < aMiddlePos) ^ (aMinPos < aMaxPos))
        return constrain(map(value, aMiddlePos, aMaxPos, this->trim - this->deadZone, 1000), this->trim, 1000);
      else
        return constrain(map(value, aMinPos, aMiddlePos, -1000, this->trim + this->deadZone), -1000, this->trim);
    }

    signed short getValue()
    {
      return getValue(tMinPos, tMiddlePos, tMaxPos);
    }

    void setTrim(short trim)
    {
      this->trim = constrain(trim, -127, 127);
    }

    void addTrim(short trimIncrement)
    {
      this->trim = constrain(this->trim + trimIncrement, -127, 127);
    }

    signed short getTrim()
    {
      return this->trim;
    }

    void setDeadZone(unsigned char deadZone)
    {
      this->deadZone = deadZone;
    }

    unsigned char getDeadZone()
    {
      return this->deadZone;
    }

  private:
    signed char trim;
    unsigned char deadZone;
  };

  template <int tPin, int tPinMode, signed short tMinPos, signed short tMaxPos>
  using PinSymmetricJoystick = Joystick<AnalogPinReader<tPin, tPinMode>, tMinPos, (tMaxPos + tMinPos) / 2, tMaxPos>;
  template <int tPin, int tPinMode, signed short tMinPos, signed short tMiddlePos, signed short tMaxPos>
  using PinJoystick = Joystick<AnalogPinReader<tPin, tPinMode>, tMinPos, tMiddlePos, tMaxPos>;
};
```


