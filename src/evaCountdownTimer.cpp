#include "evaCountdownTimer.h"
#include <Arduino.h>
#include "evaCommon.h"

using namespace eva;

void CountdownTimer::start(unsigned short period, unsigned char count, IHandler *listener)
{
    this->period = period;
    this->remainingCount = count;
    setListener(listener);
    if (this->period > 0 && count > 0)
        DelayTimer::start(this->period, this->listener);
    else
        DelayTimer::stop();
}

void eva::CountdownTimer::start(unsigned short period, unsigned char count)
{
    start(period, count, this->listener);
}

void CountdownTimer::tick()
{
    if (!isRunning())
        return;

    if (IS_BEFORE(millis(), this->nextFire))
        return;

    if (this->remainingCount-- > 0)
        this->nextFire += this->period;
    else
        stop();

    if (this->listener)
        this->listener->invoke((void *)this, {0, remainingCount});
}

CountdownTimer *CountdownTimer::setListener(IHandler *listener)
{
    return (CountdownTimer *)DelayTimer::setListener(listener);
}
