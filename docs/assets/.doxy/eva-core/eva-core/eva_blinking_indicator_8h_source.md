

# File evaBlinkingIndicator.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaBlinkingIndicator.h**](eva_blinking_indicator_8h.md)

[Go to the documentation of this file](eva_blinking_indicator_8h.md)


```C++
#ifndef EVABLINKINGINDICATOR_H
#define EVABLINKINGINDICATOR_H

#pragma once

#include "evaIndicator.h"
#include "evaHandler.h"

namespace eva
{
  class BlinkingIndicator : public Indicator, public IHandler
  {
  public:
    using Indicator::Indicator;

    void on();

    void off();

    void on(unsigned short period, unsigned char dutycyclePercent);

  protected:
    void startCycle();

  private:
    void invoke(void *msgSender, union Message message) override;

  protected:
    DelayTimer heartbeatTimer;
    DelayTimer dutycycleTimer;
    unsigned short period;
    unsigned char dutycyclePercent;
  };
}
#endif
```


