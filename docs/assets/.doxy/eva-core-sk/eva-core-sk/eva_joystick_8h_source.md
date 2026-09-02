

# File evaJoystick.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaJoystick.h**](eva_joystick_8h.md)

[Go to the documentation of this file](eva_joystick_8h.md)


```C++
#pragma once

#include "evaStdReaders.h"

namespace eva
{
  template <class TReader, unsigned short tMinPos = 0, unsigned short tMiddlePos = 512, unsigned short tMaxPos = 1024>
  class Joystick : public TReader
  {
  public:
    template <typename... Args>
    Joystick(short aDeadZone = 0, Args... args) : TReader(args...) , trim(0)
    {
       setDeadZone(aDeadZone);
    }

    template <unsigned short MINPOS, unsigned short MIDDLEPOS, unsigned short MAXPOS>
    signed short getValue()
    {
      signed short value = TReader::getValue();
      if ((value < MIDDLEPOS) ^ (MINPOS < MAXPOS))
        return constrain(map(value, MIDDLEPOS, MAXPOS, 1500 + this->trim - this->deadZone, 2000), 1500 + this->trim, 2000);
      else
        return constrain(map(value, MINPOS, MIDDLEPOS, 1000, 1500 + this->trim + this->deadZone), 1000, 1500 + this->trim);
    }

    signed short getValue()
    {
      return getValue<tMinPos, tMiddlePos, tMaxPos>();
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

    void setDeadZone(short deadZone)
    {
      this->deadZone = constrain(deadZone, 0, 255);
    }

    signed short getDeadZone()
    {
      return this->deadZone;
    }

  private:
    signed char trim;
    unsigned char deadZone;
  };

  template <int tPin, int tPinMode, unsigned short tMinPos, unsigned short tMaxPos>
  using PinSymmetricJoystick = Joystick<AnalogPinReader<tPin, tPinMode>, tMinPos, (tMaxPos + tMinPos) / 2, tMaxPos>;
  template <int tPin, int tPinMode, unsigned short tMinPos, unsigned short tMiddlePos, unsigned short tMaxPos>
  using PinJoystick = Joystick<AnalogPinReader<tPin, tPinMode>, tMinPos, tMiddlePos, tMaxPos>;
};
```


