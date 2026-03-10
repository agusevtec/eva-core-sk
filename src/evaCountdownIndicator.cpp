#include "evaCountdownIndicator.h"
using namespace eva;

void CountdownIndicator::on(unsigned short period, unsigned short dutycyclePercent, unsigned char count, IHandler *listener)
{
    this->period = period;
    this->dutycyclePercent = dutycyclePercent;
    this->countdown = count;
    this->listener = listener;
    if (this->countdown > 0)
        startCycle();
}

void CountdownIndicator::invoke(void *msgSender, CallbackInfo cbInfo)
{
    if (msgSender == &this->heartbeatTimer)
    {
        this->countdown--;
        if (this->countdown > 0)
            startCycle();
        else if (this->listener)
            this->listener->invoke(this, cbInfo);
    }
    if (msgSender == &this->dutycycleTimer)
        BlinkingIndicator::off();
}
