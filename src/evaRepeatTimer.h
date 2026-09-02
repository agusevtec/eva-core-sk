#pragma once

#include "evaDelayTimer.h"

namespace eva
{
    /**
     * @brief Timer that fires repeatedly at fixed intervals
     */
    class RepeatTimer : public DelayTimer
    {
    public:
        /**
         * @brief Constructs a RepeatTimer with no listener
         */
        using DelayTimer::DelayTimer;

        /**
         * @brief Constructs a RepeatTimer and starts it
         * @param period Interval in milliseconds
         * @param listener Handler to invoke on each tick
         */
        RepeatTimer(unsigned short period, IHandler *listener);

        /**
         * @brief Changes the timer period
         * @param period New interval in milliseconds
         * @return Pointer to this RepeatTimer instance for method chaining
         */

        RepeatTimer *setPeriod(unsigned short period);

        /**
         * @brief Assigns or changes the event listener
         * @param listener Pointer to IHandler implementation that will receive timer events
         * @return Pointer to this RepeatTimer instance for method chaining
         */
        RepeatTimer *setListener(IHandler *listener);

        /**
         * @brief Starts or restarts the repeating timer
         * @param period Interval in milliseconds
         * @param listener Handler to invoke on each tick
         */
        void start(unsigned short period, IHandler *listener);
        /**
         * @brief Starts or restarts the countdown timer
         * @param period Interval in milliseconds
         *
         * Listener must be assigned via constructor or setListener().
         * Use overloaded version with listener parameter if not pre-assigned.
         */
        void start(unsigned short period);
        /**
         * @brief Starts or restarts the countdown timer
         * @param period Interval in milliseconds
         *
         * Listener and period must be assigned via constructor or setListener() and setPeriod().
         * Use overloaded versions if not pre-assigned.
         */
        void start();

    private:
        void tick() override;

    private:
        unsigned short period;
    };
};
