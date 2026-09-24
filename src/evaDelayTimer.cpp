#include "evaDelayTimer.h"
#include <Arduino.h>

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
    start(delay);
}

void eva::DelayTimer::start(unsigned short delay)
{
    this->nextFire = millis() + delay;

    if (this->nextFire == 0) // zero value of this->nextFire means "disabled"
        this->nextFire = 1;
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

bool eva::DelayTimer::checkTimeElapsed()
{
    return millis() - this->nextFire <= 0x7FFFFFFF;
}

void DelayTimer::tick()
{
    if (!isRunning())
        return;

    if (!checkTimeElapsed())
        return;

    stop();

    if (this->listener)
        this->listener->invoke((void *)this, {0, 0});
}
