#include "evaDelayTimer.h"
#include <Arduino.h>
#include "evaCommon.h"
using namespace eva;

DelayTimer::DelayTimer()
    : listener(nullptr)
{
    stop();
}

eva::DelayTimer::DelayTimer(IHandler *listener)
{
    setListener(listener);
    stop();
}

void DelayTimer::start(unsigned short delay, IHandler *listener)
{
    setListener(listener);
    this->nextFire = millis() + delay;
    // zero value of this->nextFire means "disabled"
    if (this->nextFire == 0)
        this->nextFire = 1;
}

void eva::DelayTimer::start(unsigned short delay)
{
    start(delay, this->listener);
}

DelayTimer *eva::DelayTimer::setListener(IHandler *listener)
{
    this->listener = listener;
    return this;
}

void DelayTimer::stop()
{
    this->nextFire = 0;
}

bool DelayTimer::isRunning()
{
    return this->nextFire != 0;
}

void DelayTimer::tick()
{
    if (!isRunning())
        return;

    if (IS_BEFORE(millis(), this->nextFire))
        return;

    stop();

    if (this->listener)
        this->listener->invoke((void *)this, {0, 0});
}
