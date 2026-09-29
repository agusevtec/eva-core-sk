

# File evaSlider.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaSlider.h**](eva_slider_8h.md)

[Go to the documentation of this file](eva_slider_8h.md)


```C++
#pragma once

#include "evaStdReaders.h"
#include <Arduino.h>

namespace eva
{
  template <class TReader, signed short tMinPos = 0, signed short tMaxPos = 1024>
  class Slider : public TReader
  {
  public:
    template <typename... Args>
    Slider(Args... args) : TReader(args...)
    {
    }
    signed short getValue(signed short aMinPos, signed short aMaxPos)
    {
      return constrain(map(TReader::getValue(), aMinPos, aMaxPos, 0, 1000), 0, 1000);
    }
    signed short getValue()
    {
      return getValue(tMinPos, tMaxPos);
    }
  };
  template <signed short tPin, int tPinMode, signed short tMinPos, signed short tMaxPos>
  using PinSlider = Slider<AnalogPinReader<tPin, tPinMode>, tMinPos, tMaxPos>;
};
```


