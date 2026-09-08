

# File evaSlider.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaSlider.h**](eva_slider_8h.md)

[Go to the documentation of this file](eva_slider_8h.md)


```C++
#pragma once

#include "evaStdReaders.h"
#include <Arduino.h>

namespace eva
{
  template <class TReader, unsigned short tMinPos = 0, unsigned short tMaxPos = 1024>
  class Slider : public TReader
  {
  public:
    template <typename... Args>
    Slider(Args... args) : TReader(args...)
    {
    }
    signed short getValue(unsigned short aMinPos, unsigned short aMaxPos)
    {
      return constrain(map(TReader::getValue(), aMinPos, aMaxPos, 0, 1000), 0, 1000);
    }
    signed short getValue()
    {
      return getValue(tMinPos, tMaxPos);
    }
  };
  template <unsigned short tPin, int tPinMode, unsigned short tMinPos, unsigned short tMaxPos>
  using PinSlider = Slider<AnalogPinReader<tPin, tPinMode>, tMinPos, tMaxPos>;
};
```


