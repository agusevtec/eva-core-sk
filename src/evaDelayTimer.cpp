#include "evaDelayTimer.h"
#include <Arduino.h>

using namespace eva;

DelayTimer::DelayTimer()
    : listener(nullptr)
{
    stop();
}

void DelayTimer::start(unsigned delay, IHandler *listener)
{
    if (listener)
        this->listener = listener;
    this->nextFire = millis() + delay;
}

void DelayTimer::stop()
{
    this->nextFire = 0;
}

short DelayTimer::tick()
{
    if (!this->nextFire)
        return 0;

    if (millis() < this->nextFire)
        return 0;

    this->nextFire = 0;
    if (this->listener)
        this->listener->invoke((void *)this, 0);
    return 1;
}
