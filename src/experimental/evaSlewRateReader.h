#pragma once

#include <Arduino.h>
#include <evaHeartbeat.h>

namespace eva
{
    /**
     * @brief Reader decorator that limits maximum rate of change (slew rate / ramp).
     *
     * Prevents sharp steps by capping maximum delta per heartbeat tick.
     *
     * @tparam TReader Underlying reader class (must implement getValue())
     * @tparam tMaxStepPerTick Maximum allowed change per 10ms heartbeat tick (1..1000)
     */
    template <class TReader, unsigned short tMaxStepPerTick = 50>
    class SlewRateReader : public virtual Heartbeat, public TReader
    {
        static_assert(tMaxStepPerTick >= 1, "tMaxStepPerTick must be >= 1");

    private:
        static constexpr unsigned long kHeartbeatPeriodMs = 10;

        unsigned short mMaxStep;
        signed short mCurrentValue = 0;
        bool mInitialized = false;

    protected:
        void onHeartbeat() override
        {
            signed short target = TReader::getValue();

            if (!mInitialized)
            {
                mCurrentValue = target;
                mInitialized = true;
                return;
            }

            signed short delta = target - mCurrentValue;

            if (delta > (signed short)mMaxStep)
                mCurrentValue += mMaxStep;
            else if (delta < -(signed short)mMaxStep)
                mCurrentValue -= mMaxStep;
            else
                mCurrentValue = target;
        }

    public:
        /**
         * @brief Constructs SlewRateReader with template step limit
         * @param args Additional arguments passed to TReader constructor
         */
        template <typename... Args>
        SlewRateReader(Args... args)
            : TReader(args...), Heartbeat(kHeartbeatPeriodMs), mMaxStep(tMaxStepPerTick) {}

        /**
         * @brief Constructs SlewRateReader with runtime step limit override
         * @param aMaxStepPerTick Maximum allowed delta per tick
         * @param args Additional arguments passed to TReader constructor
         */
        template <typename... Args>
        SlewRateReader(unsigned short aMaxStepPerTick, Args... args)
            : TReader(args...), Heartbeat(kHeartbeatPeriodMs), mMaxStep(aMaxStepPerTick) {}

        /**
         * @brief Gets slew-rate limited value
         * @return Value constrained by rate limit
         */
        signed short getValue()
        {
            return mCurrentValue;
        }

        /**
         * @brief Resets current filter value instantly
         * @param initialValue Initial target value
         */
        void reset(signed short initialValue = 0)
        {
            mCurrentValue = initialValue;
            mInitialized = true;
        }

        /**
         * @brief Sets maximum step per 10ms tick
         * @param maxStep Step size limit
         */
        void setMaxStep(unsigned short maxStep)
        {
            mMaxStep = maxStep;
        }

        /**
         * @brief Gets current step size limit
         * @return Step limit per tick
         */
        unsigned short getMaxStep() const
        {
            return mMaxStep;
        }
    };

}
