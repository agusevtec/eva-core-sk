#include "evaRepeatTimer.h"
#include <Arduino.h>

using namespace eva;

RepeatTimer::RepeatTimer(unsigned period, IHandler *listener)
{
    start(period, listener);
}

void RepeatTimer::start(unsigned period, IHandler *listener)
{
    DelayTimer::start(period, listener);
    this->period = period;
}

short RepeatTimer::tick()
{
    if (DelayTimer::tick())
        this->nextFire += this->period;
    return 0;
}
