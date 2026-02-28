

# File evaDelayTimer.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaDelayTimer.h**](eva_delay_timer_8h.md)

[Go to the documentation of this file](eva_delay_timer_8h.md)


```C++
#ifndef EVADELAYTIMER_H
#define EVADELAYTIMER_H

#pragma once
#include "evaTickable.h"
#include "evaHandler.h"

namespace eva
{
    class DelayTimer : public Tickable
    {
    public:
        DelayTimer();
        
        void start(unsigned delay, IHandler *listener = 0);
        
        void stop();

    protected:
        short tick() override;

    protected:
        unsigned long nextFire;
        IHandler *listener;
    };
}


#endif
```


