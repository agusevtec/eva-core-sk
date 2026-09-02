

# File evaCountdownTimer.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaCountdownTimer.h**](eva_countdown_timer_8h.md)

[Go to the documentation of this file](eva_countdown_timer_8h.md)


```C++
#pragma once

#include "evaDelayTimer.h"

namespace eva
{
    class CountdownTimer : public DelayTimer
    {
    public:
        using DelayTimer::DelayTimer;

        CountdownTimer *setListener(IHandler *listener);

        void start(unsigned short period, unsigned char count, IHandler *listener);

        void start(unsigned short period, unsigned char count);
 
        unsigned char getRemaining();

    private:
        void tick() override;

    private:
        unsigned short period;
        unsigned char remainingCount;
    };
};
```


