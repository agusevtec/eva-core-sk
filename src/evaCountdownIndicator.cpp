#include "evaCountdownIndicator.h"
using namespace eva;

void CountdownIndicator::on(unsigned short period, unsigned short dutycyclePercent, unsigned char count, IHandler *listener)
{
    this->period = period;
    this->dutycyclePercent = dutycyclePercent;
    this->countdown = count;
    this->listener = listener;
    if (this->countdown > 0)
    {
        BlinkingIndicator::on();
        this->heartbeatTimer.start(this->period, this);
        this->dutycycleTimer.start(this->period * this->dutycyclePercent / 100, this);
    }
}

void CountdownIndicator::invoke(void *msgSender, long args)
{
    if (msgSender == &this->heartbeatTimer)
    {
        this->countdown--;
        if (this->countdown > 0)
        {
            BlinkingIndicator::on();
            this->heartbeatTimer.start(this->period, this);
            this->dutycycleTimer.start(this->period * this->dutycyclePercent / 100, this);
        }
        else
        {
            if (this->listener)
                this->listener->invoke(this, 0);
        }
    }
    if (msgSender == &this->dutycycleTimer)
    {
        BlinkingIndicator::off();
    }
}

