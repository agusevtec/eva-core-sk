

# File evaIndicator.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaIndicator.h**](eva_indicator_8h.md)

[Go to the documentation of this file](eva_indicator_8h.md)


```C++
#ifndef EVAINDICATOR_H_
#define EVAINDICATOR_H_
#include "evaDelayTimer.h"

#include <Arduino.h>

namespace eva
{
  class Indicator
  {
  public:
    Indicator(unsigned pin, int activationLevel = HIGH);
    
    void on();
    
    void off();

  private:
    int pin;
    unsigned char activationLevel;
  };


}

#endif
```


