

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
  template <class READER, unsigned short MIN_POS, unsigned short MAX_POS>
  class Slider : public READER
  {
  public:
    signed short getValue()
    {
      return constrain(map(READER::getValue(), MIN_POS, MAX_POS, 1000, 2000), 1000, 2000);
    }
  };
  template <unsigned short PIN, int PIN_MODE, unsigned short MIN_POS, unsigned short MAX_POS>
  using PinSlider = Slider<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, MAX_POS>;
};

#endif
```


