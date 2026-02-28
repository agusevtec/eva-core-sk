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
  this->dutycycleTimer.start(this->period * this->dutycyclePercent / 100, this);
}

void BlinkingIndicator::on(unsigned short period, unsigned char dutycyclePercent)
{
  this->period = period;
  this->dutycyclePercent = dutycyclePercent;
  startCycle();
}

void BlinkingIndicator::invoke(void *msgSender, long args)
{
  if (msgSender == &this->heartbeatTimer)
    startCycle();

  if (msgSender == &this->dutycycleTimer)
    off();
}