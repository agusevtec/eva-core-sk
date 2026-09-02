

# File evaRepeatTimer.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaRepeatTimer.h**](eva_repeat_timer_8h.md)

[Go to the documentation of this file](eva_repeat_timer_8h.md)


```C++
#pragma once

#include "evaDelayTimer.h"

namespace eva
{
    class RepeatTimer : public DelayTimer
    {
    public:
        using DelayTimer::DelayTimer;

        RepeatTimer(unsigned short period, IHandler *listener);


        RepeatTimer *setPeriod(unsigned short period);

        RepeatTimer *setListener(IHandler *listener);

        void start(unsigned short period, IHandler *listener);
        void start(unsigned short period);
        void start();

    private:
        void tick() override;

    private:
        unsigned short period;
    };
};
```


