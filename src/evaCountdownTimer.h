#pragma once

#include "evaDelayTimer.h"

namespace eva
{
    /**
     * @brief Timer that fires a specified number of times at fixed intervals
     */
    class CountdownTimer : public DelayTimer
    {
    public:
        /**
         * @brief Constructs a CountdownTimer
         */
        using DelayTimer::DelayTimer;

        /**
         * @brief Assigns or changes the event listener
         * @param listener Pointer to IHandler implementation that will receive timer events
         * @return Pointer to this CountdownTimer instance for method chaining
         */
        CountdownTimer *setListener(IHandler *listener);

        /**
         * @brief Starts or restarts the repeating timer
         * @param period Interval in milliseconds
         * @param count Number of iterations
         * @param listener Handler to invoke on each tick
         */
        void start(unsigned short period, unsigned char count, IHandler *listener);

        /**
         * @brief Starts or restarts the countdown timer
         * @param period Interval in milliseconds
         * @param count Number of iterations
         *
         * Listener must be assigned via constructor or setListener().
         * Use overloaded version with listener parameter if not pre-assigned.
         */
        void start(unsigned short period, unsigned char count);
 
        /**
         * @brief Returns the number of remaining timer ticks
         * @return Number of pending executions (0 if timer is not running)
         */
        unsigned char getRemaining();

    private:
        void tick() override;

    private:
        unsigned short period;
        unsigned char remainingCount;
    };
};
