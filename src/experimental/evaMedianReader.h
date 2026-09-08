#pragma once

#include <Arduino.h>
#include <evaHeartbeat.h>

namespace eva
{
    constexpr unsigned short kDefaultWindowSize = 5;
    constexpr unsigned short kMinWindowSize = 3;
    constexpr unsigned short kMaxWindowSize = 15;

    /**
     * @brief Reader decorator applying median filtering on a fixed time base.
     * @tparam TReader Underlying reader class (must implement getValue())
     * @tparam tWindowSize Filter window size (odd number)
     */
    template <class TReader, unsigned short tWindowSize = kDefaultWindowSize>
    class MedianReader : public virtual Heartbeat, public TReader
    {
        static_assert(tWindowSize >= kMinWindowSize && tWindowSize <= kMaxWindowSize,
                      "tWindowSize out of range");
        static_assert(tWindowSize % 2 == 1,
                      "tWindowSize must be odd");

    private:
        static constexpr unsigned long kHeartbeatPeriodMs = 10;

        signed short mBuffer[tWindowSize];
        unsigned short mIndex = 0;
        bool mBufferFull = false;
        signed short mFilteredValue = 0;

        signed short calculateMedian()
        {
            signed short sorted[tWindowSize];
            unsigned short count = mBufferFull ? tWindowSize : mIndex + 1;

            for (unsigned short i = 0; i < count; i++)
                sorted[i] = mBuffer[i];

            for (unsigned short i = 0; i < count - 1; i++)
            {
                for (unsigned short j = 0; j < count - i - 1; j++)
                {
                    if (sorted[j] > sorted[j + 1])
                    {
                        signed short temp = sorted[j];
                        sorted[j] = sorted[j + 1];
                        sorted[j + 1] = temp;
                    }
                }
            }

            return sorted[count / 2];
        }

    protected:
        void onHeartbeat() override
        {
            mBuffer[mIndex] = constrain(TReader::getValue(), -1000, 1000);
            mIndex++;
            if (mIndex >= tWindowSize)
            {
                mIndex = 0;
                mBufferFull = true;
            }

            if (mBufferFull || mIndex > tWindowSize / 2)
            {
                mFilteredValue = calculateMedian();
            }
        }

    public:
        template <typename... Args>
        MedianReader(Args... args) : TReader(args...), Heartbeat(kHeartbeatPeriodMs)
        {
            for (unsigned short i = 0; i < tWindowSize; i++)
                mBuffer[i] = 0;
        }

        void reset()
        {
            mIndex = 0;
            mBufferFull = false;
            mFilteredValue = 0;
            for (unsigned short i = 0; i < tWindowSize; i++)
                mBuffer[i] = 0;
        }

        signed short getValue()
        {
            return mFilteredValue;
        }
    };

}
