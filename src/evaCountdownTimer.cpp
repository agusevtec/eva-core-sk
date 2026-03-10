#include "evaCountdownTimer.h"
#include <Arduino.h>

using namespace eva;

void ContdownTimer::start(unsigned short period, unsigned short count, IHandler *listener)
{
    this->period = period;
    this->remainingCount = count;
    setListener(listener);
    if (this->period > 0 && count > 0)
        DelayTimer::start(this->period, this->listener);
    else
        DelayTimer::stop();
}

void eva::ContdownTimer::start(unsigned short period, unsigned short count)
{
    start(period, count, this->listener);
}

void ContdownTimer::tick()
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

ContdownTimer *ContdownTimer::setListener(IHandler *listener)
{
    return (ContdownTimer *)DelayTimer::setListener(listener);
}
