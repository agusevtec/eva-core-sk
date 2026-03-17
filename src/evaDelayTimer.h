#ifndef EVADELAYTIMER_H
#define EVADELAYTIMER_H

#pragma once
#include "evaTickable.h"
#include "evaHandler.h"

#define IS_BEFORE(t1, t2) (((t2) - (t1)) <= 0x7FFFFFFFUL)


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

        /**
         * @brief Starts the timer
         * @param delay Delay in milliseconds
         *
         * Listener must be assigned via constructor or setListener().
         * Use overloaded version with listener parameter if not pre-assigned.
         */
        void start(unsigned short delay);

        /**
         * @brief Checks if the timer is currently active
         * @return true if timer is running and will fire, false otherwise
         */
        bool isRunning();

        /**
         * @brief Assigns or changes the event listener
         * @param listener Pointer to IHandler implementation that will receive timer events
         * @return Pointer to this DelayTimer instance for method chaining
         */
        DelayTimer *setListener(IHandler *listener);

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
