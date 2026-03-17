

# File evaJoystick.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaJoystick.h**](eva_joystick_8h.md)

[Go to the documentation of this file](eva_joystick_8h.md)


```C++
#ifndef EVAJOYSTICK_H_
#define EVAJOYSTICK_H_
#include "evaStdReaders.h"

namespace eva
{
  inline static signed short SIGN(signed short x)
  {
    return (((x) > 0) - ((x) < 0));
  }
  template <class READER, int MIN, int MIDDLE, int MAX>
  class Joystick : public READER
  {
  public:
    signed char getValue()
    {
      signed short value = READER::getValue();
      if (SIGN(MIDDLE - value) * SIGN(MAX - MIN) >= 0)
        return constrain(map(value, MIN, MIDDLE, -127, this->trim), -127, this->trim);
      else
        return constrain(map(value, MIDDLE, MAX, this->trim, 127), this->trim, 127);
    }

    void setTrim(short trim)
    {
      this->trim = trim;
    }

    signed short getTrim()
    {
      return this->trim;
    }

  private:
    signed short trim;
  };
  template <int PIN, int PIN_MODE, int MIN, int MAX>
  using PinSymmetricJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN, (MAX - MIN) / 2, MAX>;
  template <int PIN, int PIN_MODE, int MIN, int MIDDLE, int MAX>
  using PinJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN, MIDDLE, MAX>;
};

#endif
```


