#include "evaCountdownTimer.h"
#include <Arduino.h>

using namespace eva;

void CountdownTimer::start(unsigned short period, unsigned short count, IHandler *listener)
{
    this->period = period;
    this->remainingCount = count;
    setListener(listener);
    if (this->period > 0 && count > 0)
        DelayTimer::start(this->period, this->listener);
    else
        DelayTimer::stop();
}

void eva::CountdownTimer::start(unsigned short period, unsigned short count)
{
    start(period, count, this->listener);
}

void CountdownTimer::tick()
{
    if (!isRunning())
        return;

    DelayTimer::tick();

    if (!isRunning())
    {
        remainingCount--;
        if (this->remainingCount > 1)
            this->nextFire += this->period;
        {
            stop();
            return;
        }
    }
}

CountdownTimer *CountdownTimer::setListener(IHandler *listener)
{
    return (CountdownTimer *)DelayTimer::setListener(listener);
}
