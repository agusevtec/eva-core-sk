#ifndef EVASLIDER_H_
#define EVASLIDER_H

#include "evaStdReaders.h"
#include <Arduino.h>

namespace eva
{
  template <class READER, int MIN, int MAX>
  class Slider : public READER
  {
  public:
    signed short getValue()
    {
      return constrain(map(READER::getValue(), MIN, MAX, 0, 255), 0, 255);
    }
  };

  template <int PIN, int PINMODE, int MIN, int MAX>
  using PinSlider = Slider<AnalogPinReader<PIN, PINMODE>, MIN, MAX>;
};

#endif
