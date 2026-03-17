#include "evaBlinkingIndicator.h"
using namespace eva;

void BlinkingIndicator::on()
{
  Indicator::on();
  this->heartbeatTimer.stop();
  this->dutycycleTimer.stop();
}

void BlinkingIndicator::off()
{
  Indicator::off();
  this->heartbeatTimer.stop();
  this->dutycycleTimer.stop();
}

void BlinkingIndicator::startCycle()
{
  Indicator::on();
  this->heartbeatTimer.start(this->period, this);
  this->dutycycleTimer.start(((long)this->period * (long)this->dutycyclePercent) / 100, this);
}

void BlinkingIndicator::on(unsigned short period, unsigned char dutycyclePercent)
{
  this->period = period;
  this->dutycyclePercent = constrain(dutycyclePercent, 0, 100);
  startCycle();
}

void BlinkingIndicator::invoke(void *msgSender, CallbackInfo)
{
  if (msgSender == &(this->heartbeatTimer))
    startCycle();

  if (msgSender == &(this->dutycycleTimer))
    Indicator::off();
}
