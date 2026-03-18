#ifndef COUNTDOWNINDICATOR_H
#define COUNTDOWNINDICATOR_H

#pragma once

#include "evaBlinkingIndicator.h"

namespace eva
{
    /**
     * @brief Indicator that blinks a specified number of times then notifies listener
     * 
     * Note:
     * This class serves as a demonstration of library concepts and is intentionally
     * kept simple for clarity. Performance optimization was not the primary focus.
     * It is recommended for prototyping stages to validate your application logic.
     * For production use with strict timing requirements, consider implementing
     * a custom solution based on your specific needs.
     */
    class CountdownIndicator : public BlinkingIndicator
    {
    public:
        using BlinkingIndicator::BlinkingIndicator;
        using BlinkingIndicator::on;

        /**
         * @brief Assigns or changes the event listener
         * @param listener Pointer to IHandler implementation that will receive timer events
         * @return Pointer to this DelayTimer instance for method chaining
         */
        CountdownIndicator *setListener(IHandler *listener);

        /**
         * @brief Starts countdown blinking
         * @param period Blinking period in milliseconds
         * @param dutycyclePercent On-time percentage
         * @param count Number of blinks before stopping
         */
        void on(unsigned short period, unsigned char dutycyclePercent, unsigned char count);

        /**
         * @brief Starts countdown blinking
         * @param period Blinking period in milliseconds
         * @param dutycyclePercent On-time percentage
         * @param count Number of blinks before stopping
         * @param listener Handler to notify when countdown completes
         */
        void on(unsigned short period, unsigned char dutycyclePercent, unsigned char count, IHandler *listener);

    private:
        void invoke(void *msgSender, CallbackInfo cbInfo) override;

    private:
        unsigned char countdown;
        IHandler *listener;
    };
}

#endif
