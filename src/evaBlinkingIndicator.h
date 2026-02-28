#ifndef EVABLINKINGINDICATOR_H
#define EVABLINKINGINDICATOR_H

#pragma once

#include "evaIndicator.h"
#include "evaHandler.h"

namespace eva
{
  /**
   * @brief Indicator that blinks with specified period and duty cycle
   */
  class BlinkingIndicator : public Indicator, public IHandler
  {
  public:
    using Indicator::Indicator;

    /**
     * @brief Turns on the indicator continuously
     */
    void on();

    /**
     * @brief Turns off the indicator
     */
    void off();

    /**
     * @brief Turns on the indicator with blinking pattern
     * @param period Blinking period in milliseconds
     * @param dutycyclePercent On-time percentage (0-100)
     */
    void on(unsigned short period, unsigned char dutycyclePercent);

  protected:
    void startCycle();

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
