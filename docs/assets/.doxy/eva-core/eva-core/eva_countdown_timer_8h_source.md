

# File evaCountdownTimer.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaCountdownTimer.h**](eva_countdown_timer_8h.md)

[Go to the documentation of this file](eva_countdown_timer_8h.md)


```C++
#ifndef EVACOUNTDOWNTIMER_H
#define EVACOUNTDOWNTIMER_H

#pragma once
#include "evaDelayTimer.h"

namespace eva
{
    class ContdownTimer : public DelayTimer
    {
    public:
        using DelayTimer::DelayTimer;

        ContdownTimer *setListener(IHandler *listener);

        void start(unsigned short period, unsigned short count, IHandler *listener = nullptr);
        void start(unsigned short period, unsigned short count);

    private:
        void tick() override;

    private:
        unsigned short period;
        unsigned short remainingCount;
    };
};

#endif
```


