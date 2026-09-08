#pragma once

#include <Arduino.h>
#include <evaHeartbeat.h>

namespace eva
{
    constexpr unsigned short kDefaultMinTimeConstantMs = 10;
    constexpr unsigned short kDefaultMaxTimeConstantMs = 150;
    constexpr unsigned short kMinTimeConstantLimit = 5;
    constexpr unsigned short kMaxTimeConstantLimit = 500;

    /**
     * @brief Reader decorator with adaptive smoothing based on input rate of change.
     * @tparam TReader Underlying reader class (must implement getValue())
     * @tparam tMinTimeConstantMs Minimum time constant (fast response)
     * @tparam tMaxTimeConstantMs Maximum time constant (heavy smoothing)
     */
    template <class TReader,
              unsigned short tMinTimeConstantMs = kDefaultMinTimeConstantMs,
              unsigned short tMaxTimeConstantMs = kDefaultMaxTimeConstantMs>
    class AdaptiveSmoothReader : public virtual Heartbeat, public TReader
    {
        static_assert(tMinTimeConstantMs >= kMinTimeConstantLimit && tMinTimeConstantMs <= kMaxTimeConstantLimit,
                      "tMinTimeConstantMs out of range");
        static_assert(tMaxTimeConstantMs >= tMinTimeConstantMs && tMaxTimeConstantMs <= kMaxTimeConstantLimit,
                      "tMaxTimeConstantMs must be >= tMinTimeConstantMs");

    private:
        static constexpr unsigned long kHeartbeatPeriodMs = 10;
        static constexpr signed short kDeadzone = 3;

        unsigned short mMinTimeConstantMs;
        unsigned short mMaxTimeConstantMs;

        signed short mTargetValue = 0;
        signed short mCurrentValue = 0;
        signed short mLastTargetValue = 0;
        unsigned short mCurrentTimeConstantMs = tMaxTimeConstantMs;

        unsigned short calculateTimeConstant()
        {
            signed short change = abs(mTargetValue - mLastTargetValue);

            if (change >= 200)
                return mMinTimeConstantMs;
            else if (change <= 5)
                return mMaxTimeConstantMs;
            else
            {
                return mMaxTimeConstantMs - ((change - 5) * (mMaxTimeConstantMs - mMinTimeConstantMs) / 195);
            }
        }

    protected:
        void onHeartbeat() override
        {
            mTargetValue = constrain(TReader::getValue(), -1000, 1000);
            mCurrentTimeConstantMs = calculateTimeConstant();
            mLastTargetValue = mTargetValue;

            if (abs(mTargetValue) <= kDeadzone && abs(mCurrentValue) <= kDeadzone)
            {
                if (mCurrentValue != 0)
                    mCurrentValue = 0;
            }
            else
            {
                signed long step = (signed long)(mTargetValue - mCurrentValue) * kHeartbeatPeriodMs * 1000 / mCurrentTimeConstantMs;
                mCurrentValue += step / 1000;
                mCurrentValue = constrain(mCurrentValue, -1000, 1000);
            }
        }

    public:
        template <typename... Args>
        AdaptiveSmoothReader(unsigned short aMinTimeConstantMs, unsigned short aMaxTimeConstantMs, Args... args)
            : TReader(args...),
              Heartbeat(kHeartbeatPeriodMs),
              mMinTimeConstantMs(constrain(aMinTimeConstantMs, kMinTimeConstantLimit, kMaxTimeConstantLimit)),
              mMaxTimeConstantMs(constrain(aMaxTimeConstantMs, mMinTimeConstantMs, kMaxTimeConstantLimit))
        {
        }

        template <typename... Args>
        AdaptiveSmoothReader(Args... args)
            : TReader(args...),
              Heartbeat(kHeartbeatPeriodMs),
              mMinTimeConstantMs(tMinTimeConstantMs),
              mMaxTimeConstantMs(tMaxTimeConstantMs)
        {
        }

        signed short getValue()
        {
            return mCurrentValue;
        }

        void setMinTimeConstantMs(unsigned short value)
        {
            mMinTimeConstantMs = constrain(value, kMinTimeConstantLimit, kMaxTimeConstantLimit);
        }

        unsigned short getMinTimeConstantMs() const
        {
            return mMinTimeConstantMs;
        }

        void setMaxTimeConstantMs(unsigned short value)
        {
            mMaxTimeConstantMs = constrain(value, mMinTimeConstantMs, kMaxTimeConstantLimit);
        }

        unsigned short getMaxTimeConstantMs() const
        {
            return mMaxTimeConstantMs;
        }

        void setupRange(unsigned short minTimeConstantMs, unsigned short maxTimeConstantMs)
        {
            setMinTimeConstantMs(minTimeConstantMs);
            setMaxTimeConstantMs(maxTimeConstantMs);
        }
    };

}
