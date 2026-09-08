#pragma once

#include "evaRingBuffer.h"

namespace eva
{
    /**
     * @brief Reader decorator applying a moving average filter.
     * @tparam TReader Underlying reader class (must implement getValue())
     * @tparam N Window size. Must be >= 1.
     */
    template <class TReader, unsigned short N>
    class SlidingWindowReader : public TReader
    {
        static_assert(N >= 1 && N <= 32, "N out of range 1..32");

    private:
        RingBuffer<signed short, N> mRing;
        signed long mSum = 0;

    public:
        template <typename... Args>
        SlidingWindowReader(Args... args) : TReader(args...) {}

        signed short getValue()
        {
            signed short value = TReader::getValue();

            if (mRing.isFull())
                mSum -= mRing.get(0);

            mRing.put(value);
            mSum += value;

            if (mRing.isFull())
                value = static_cast<signed short>(mSum / N);

            return value;
        }
    };

}
