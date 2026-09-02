

# File evaCountdownIndicator.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaCountdownIndicator.h**](eva_countdown_indicator_8h.md)

[Go to the documentation of this file](eva_countdown_indicator_8h.md)


```C++
#pragma once

#include "evaBlinkingIndicator.h"

namespace eva
{
    class CountdownIndicator : public BlinkingIndicator
    {
    public:
        using BlinkingIndicator::BlinkingIndicator;
        using BlinkingIndicator::on;

        CountdownIndicator *setListener(IHandler *listener);

        void on(unsigned short period, unsigned char dutycyclePercent, unsigned char count);

        void on(unsigned short period, unsigned char dutycyclePercent, unsigned char count, IHandler *listener);

    private:
        void invoke(void *msgSender, CallbackInfo cbInfo) override;

    private:
        unsigned char countdown;
        IHandler *listener;
    };
}
```


