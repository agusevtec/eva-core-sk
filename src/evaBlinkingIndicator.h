#ifndef EVABLINKINGINDICATOR_H
#define EVABLINKINGINDICATOR_H

#pragma once

#include "evaIndicator.h"
#include "evaHandler.h"

namespace eva
{
 /**
 * @brief Indicator that blinks with specified period and duty cycle
 * 
 * Note:
 * This class serves as a demonstration of library concepts and is intentionally
 * kept simple for clarity. Performance optimization was not the primary focus.
 * It is recommended for prototyping stages to validate your application logic.
 * For production use with strict timing requirements, consider implementing
 * a custom solution based on your specific needs.
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
    void invoke(void *msgSender, CallbackInfo cbInfo) override;

  protected:
    DelayTimer heartbeatTimer;
    DelayTimer dutycycleTimer;
    unsigned short period;
    unsigned char dutycyclePercent;
  };
}
#endif
