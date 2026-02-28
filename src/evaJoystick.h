#ifndef EVAJOYSTICK_H_
#define EVAJOYSTICK_H_
#include "evaStdReaders.h"

namespace eva
{
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

  template <int PIN, int PINMODE, int MIN, int MAX>
  using PinJoystick = Joystick<AnalogPinReader<PIN, PINMODE>, MIN, (MAX - MIN) / 2, MAX>;

  template <int PIN, int PINMODE, int MIN, int MIDDLE, int MAX>
  using PinJoystick = Joystick<AnalogPinReader<PIN, PINMODE>, MIN, MIDDLE, MAX>;
};

#endif
