

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
        
        DelayTimer(IHandler *listener);

        void start(unsigned short delay, IHandler *listener);

        void start(unsigned short delay);

        bool isRunning();

        DelayTimer* setListener(IHandler *listener);
        
        void stop();

    protected:
        void tick() override;

    protected:
        unsigned long nextFire;
        IHandler *listener;
    };
}


#endif
```


