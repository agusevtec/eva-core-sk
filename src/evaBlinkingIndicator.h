#ifndef EVABLINKINGINDICATOR_H
#define EVABLINKINGINDICATOR_H

#pragma once

#include "evaIndicator.h"
#include "evaHandler.h"

namespace eva
{
  class BlinkingIndicator : public Indicator, public IHandler
  {
  public:
    using Indicator::Indicator;
    void on();
    void off();
    void on(unsigned short period, unsigned char dutycyclePercent);

  private:
    void invoke(void *msgSender, long args) override;

  protected:
    DelayTimer heartbeatTimer;
    DelayTimer dutycycleTimer;
    unsigned short period;
    unsigned char dutycyclePercent;
  };
}
#endif