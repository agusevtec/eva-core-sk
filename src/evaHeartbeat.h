#pragma once

#include "evaTickable.h"

namespace eva
{
    /**
     * @brief Base class for components that need periodic updates.
     *
     * Provides a simple heartbeat mechanism with fixed period.
     * Derived classes must implement onHeartbeat() which will be called
     * at regular intervals.
     *
     * The period is set at construction and cannot be changed (immutable).
     */
    class Heartbeat : public Tickable
    {
    private:
        const unsigned long periodMs;
        unsigned long lastBeatMs;

    protected:
        /**
         * @brief Virtual method to be overridden by derived classes.
         * Called at each heartbeat interval.
         */
        virtual void onHeartbeat() = 0;

    public:
        /**
         * @brief Constructor with fixed period.
         * @param periodMs Heartbeat period in milliseconds.
         */
        Heartbeat(unsigned long periodMs);

        /**
         * @brief Virtual destructor.
         */
        virtual ~Heartbeat() = default;

        /**
         * @brief Update method - call this regularly from main loop.
         * Checks if period has elapsed and calls onHeartbeat() if needed.
         */
        void tick() override;

        /**
         * @brief Get the heartbeat period.
         * @return Period in milliseconds (immutable).
         */
        unsigned long getPeriod() const;
    };

}
