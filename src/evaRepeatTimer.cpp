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
    DelayTimer::start(period, listener);
}

void RepeatTimer::start(unsigned short period)
{
    setPeriod(period);
    DelayTimer::start(period);
}

void RepeatTimer::start()
{
    DelayTimer::start(this->period);
}

void RepeatTimer::tick()
{
    if (!isRunning())
        return;

    if (!this->checkTimeElapsed())
        return;

    DelayTimer::start(this->period);

    if (this->listener)
        this->listener->invoke((void *)this, {0, 0});
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
