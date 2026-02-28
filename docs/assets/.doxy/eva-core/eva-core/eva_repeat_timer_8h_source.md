

# File evaRepeatTimer.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaRepeatTimer.h**](eva_repeat_timer_8h.md)

[Go to the documentation of this file](eva_repeat_timer_8h.md)


```C++
#ifndef EVAREPEATTIMER_H
#define EVAREPEATTIMER_H

#pragma once
#include "evaDelayTimer.h"

namespace eva
{
    class RepeatTimer : public DelayTimer
    {
    public:
        using DelayTimer::DelayTimer;
        
        RepeatTimer(unsigned period, IHandler *listener);
        
        void start(unsigned period, IHandler *listener);

    private:
        short tick() override;

    private:
        unsigned short period;
    };
};

#endif
```


