#include "evaCountdownIndicator.h"
using namespace eva;

CountdownIndicator *eva::CountdownIndicator::setListener(IHandler *listener)
{
    this->listener = listener;
    Serial.print("set-listener: ");
    Serial.println((long)this->listener);
    return this;
}

void CountdownIndicator::on(unsigned short period, unsigned char dutycyclePercent, unsigned char count, IHandler *listener)
{
    this->period = period;
    this->dutycyclePercent = dutycyclePercent;
    this->countdown = count;
    this->listener = listener;
    if (this->countdown > 0)
        this->startCycle();
}

void CountdownIndicator::on(unsigned short period, unsigned char dutycyclePercent, unsigned char count)
{
    on(period, dutycyclePercent, count, this->listener);
}

void CountdownIndicator::invoke(void *msgSender, CallbackInfo)
{
    if (msgSender == &(this->heartbeatTimer))
    {
        if (--this->countdown > 0)
            this->startCycle();

        if (this->countdown == 0)
            if (this->listener)
                this->listener->invoke(this, {0, 0});
    }
    if (msgSender == &(this->dutycycleTimer))
        Indicator::off();
}
