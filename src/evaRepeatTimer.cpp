#include "evaRepeatTimer.h"
#include <Arduino.h>

using namespace eva;

RepeatTimer::RepeatTimer(unsigned short period, IHandler *listener)
{
    start(period, listener);
}

void RepeatTimer::start(unsigned short period, IHandler *listener)
{
    setPeriod(period);
    setListener(listener);
    if (this->period > 0)
        DelayTimer::start(this->period, this->listener);
    else
        stop();
}

void eva::RepeatTimer::start(unsigned short period)
{
    start(period, this->listener);
}

void eva::RepeatTimer::start()
{
    start(this->period, this->listener);
}

void RepeatTimer::tick()
{
    if (!isRunning())
        return;
    unsigned long nf = this->nextFire;

    DelayTimer::tick();

    if (!isRunning())
        this->nextFire = nf + this->period;
}

RepeatTimer *RepeatTimer::setPeriod(unsigned short period)
{
    this->period = period;
    return this;
}

RepeatTimer *RepeatTimer::setListener(IHandler *listener)
{
    return (RepeatTimer *)DelayTimer::setListener(listener);
}
