#ifndef EVACOUNTDOWNTIMER_H
#define EVACOUNTDOWNTIMER_H

#pragma once
#include "evaDelayTimer.h"

namespace eva
{
    /**
     * @brief Timer that fires repeatedly at fixed intervals
     */
    class CountdownTimer : public DelayTimer
    {
    public:
        using DelayTimer::DelayTimer;

        CountdownTimer *setListener(IHandler *listener);

        /**
         * @brief Starts or restarts the repeating timer
         * @param period Interval in milliseconds
         * @param listener Handler to invoke on each tick
         */
        void start(unsigned short period, unsigned char count, IHandler *listener);
        void start(unsigned short period, unsigned char count);

    private:
        void tick() override;

    private:
        unsigned short period;
        unsigned char remainingCount;
    };
};

#endif
