#ifndef EVADELAYTIMER_H
#define EVADELAYTIMER_H

#pragma once
#include "evaTickable.h"
#include "evaHandler.h"

namespace eva
{
    /**
     * @brief One-shot timer that fires after a delay
     */
    class DelayTimer : public Tickable
    {
    public:
        DelayTimer();
        
        DelayTimer(IHandler *listener);

        /**
         * @brief Starts the timer
         * @param delay Delay in milliseconds
         * @param listener Handler to invoke when timer expires
         */
        void start(unsigned short delay, IHandler *listener);

        void start(unsigned short delay);

        bool isRunning();

        DelayTimer* setListener(IHandler *listener);
        
        /**
         * @brief Stops the timer
         */
        void stop();

    protected:
        void tick() override;

    protected:
        unsigned long nextFire;
        IHandler *listener;
    };
}


#endif
