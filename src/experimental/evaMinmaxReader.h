#pragma once

#include "evaRingBuffer.h"

namespace eva
{
    /**
     * @brief Reader decorator applying a min-max (morphological) filter.
     * @tparam TReader Underlying reader class (must implement getValue())
     * @tparam N Number of chunks and chunk size (total buffer size = N * N)
     */
    template <class TReader, unsigned char N>
    class MinmaxReader : public TReader
    {
        static_assert(N >= 2 && N <= 5, "N out of range 2..5");

    private:
        RingBuffer<signed short, N * N> mRing;
        signed short mMaxBuffer[N];
        signed short mMinBuffer[N];

    public:
        template <typename... Args>
        MinmaxReader(Args... args) : TReader(args...)
        {
            for (unsigned char i = 0; i < N; ++i)
            {
                mMaxBuffer[i] = 0;
                mMinBuffer[i] = 0;
            }
        }

        signed short getValue()
        {
            signed short value = TReader::getValue();
            mRing.put(value);

            if (mRing.isFull())
            {
                for (unsigned char chunk = 0; chunk < N; chunk++)
                {
                    unsigned char start = chunk * N;
                    signed short maxVal = mRing.get(start);
                    signed short minVal = maxVal;

                    for (unsigned char i = 1; i < N; ++i)
                    {
                        signed short val = mRing.get(start + i);
                        if (val > maxVal)
                            maxVal = val;
                        if (val < minVal)
                            minVal = val;
                    }

                    mMaxBuffer[chunk] = maxVal;
                    mMinBuffer[chunk] = minVal;
                }

                value = (getMinimax() + getMaximin()) / 2;
            }

            return value;
        }

    private:
        signed short getMinimax() const
        {
            signed short result = mMaxBuffer[0];
            for (unsigned char i = 1; i < N; ++i)
                if (mMaxBuffer[i] < result)
                    result = mMaxBuffer[i];
            return result;
        }

        signed short getMaximin() const
        {
            signed short result = mMinBuffer[0];
            for (unsigned char i = 1; i < N; ++i)
                if (mMinBuffer[i] > result)
                    result = mMinBuffer[i];
            return result;
        }
    };

}
