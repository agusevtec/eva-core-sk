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
