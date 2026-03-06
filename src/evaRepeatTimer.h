#ifndef EVAREPEATTIMER_H
#define EVAREPEATTIMER_H

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
        using DelayTimer::DelayTimer;
       
        /**
         * @brief Constructor that starts the timer
         * @param period Interval in milliseconds
         * @param listener Handler to invoke on each tick
         */
        RepeatTimer(unsigned short period, IHandler *listener);

        RepeatTimer* setPeriod(unsigned short period);
        
        RepeatTimer* setListener(IHandler *listener);
        
        /**
         * @brief Starts or restarts the repeating timer
         * @param period Interval in milliseconds 
         * @param listener Handler to invoke on each tick
         */
        void start(unsigned short period, IHandler *listener);
        void start(unsigned short period);
        void start();

    private:
        void tick() override;

    private:
        unsigned short period;
    };
};

#endif
