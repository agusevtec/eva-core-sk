

# File evaSlider.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaSlider.h**](eva_slider_8h.md)

[Go to the documentation of this file](eva_slider_8h.md)


```C++
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
  template <int PIN, int PIN_MODE, int MIN, int MAX>
  using PinSlider = Slider<AnalogPinReader<PIN, PIN_MODE>, MIN, MAX>;
};

#endif
```


