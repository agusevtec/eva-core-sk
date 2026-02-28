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
