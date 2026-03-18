

# File evaJoystick.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaJoystick.h**](eva_joystick_8h.md)

[Go to the documentation of this file](eva_joystick_8h.md)


```C++
#ifndef EVAJOYSTICK_H_
#define EVAJOYSTICK_H_
#include "evaStdReaders.h"

namespace eva
{
  template <class READER, int MIN_POS, int MIDDLE_POS, int MAX_POS>
  class Joystick : public READER
  {
  public:
    signed short getValue()
    {
      signed short value = READER::getValue();
      if ((value < MIDDLE_POS) ^ (MIN_POS < MAX_POS))
        return constrain(map(value, MIDDLE_POS, MAX_POS, 1500 + this->trim - this->deadZone, 2000), 1500 + this->trim, 2000);
      else
        return constrain(map(value, MIN_POS, MIDDLE_POS, 1000, 1500 + this->trim + this->deadZone), 1000, 1500 + this->trim);
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
    signed char trim = 0;
    unsigned char deadZone = 0;
  };
  template <int PIN, int PIN_MODE, int MIN_POS, int MAX_POS>
  using PinSymmetricJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, (MAX_POS - MIN_POS) / 2, MAX_POS>;
  template <int PIN, int PIN_MODE, int MIN_POS, int MIDDLE_POS, int MAX_POS>
  using PinJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, MIDDLE_POS, MAX_POS>;
};

#endif
```


