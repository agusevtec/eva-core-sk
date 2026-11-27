#pragma once

#include <Arduino.h>

namespace eva
{
    static const unsigned short kDebounceDelay = 120;

    /**
     * @brief Checks if value x is between a and b (inclusive)
     * @param x Value to check
     * @param a Lower bound
     * @param b Upper bound
     * @return true if x is between a and b inclusive
     */
    inline static bool in_between(signed short x, signed short a, signed short b)
    {
        if ((a <= b) && (a <= x) && (x <= b))
            return true;
        if ((b <= a) && (b <= x) && (x <= a))
            return true;
        return false;
    }

    /**
     * @brief Rate-limiting decorator for contact-bounce suppression.
     *
     * The first change of the underlying reading is accepted immediately;
     * after that, further changes are ignored for tDebounceDelay ms.
     * Readings taken during that window return the accepted value without
     * polling the underlying reader.
     *
     * Note: this is NOT a "value must stay stable for tDebounceDelay ms"
     * debounce. Short glitches that occur right after an accepted change
     * are filtered out by the lock window, but a glitch that arrives when
     * no lock is active will be accepted as a new value.
     *
     * @tparam TReader Underlying reader type
     * @tparam tDebounceDelay Lock window after an accepted change, ms
     */
    template <class TReader, int tDebounceDelay = kDebounceDelay>
    class DebounceDecor : public TReader
    {
    public:
        /**
         * @brief Constructs a DebounceDecor
         * @param args Additional arguments passed to TReader constructor
         */
        template <typename... Args>
        DebounceDecor(Args... args) : TReader(args...)
        {
        }
        /**
         * @brief Gets debounced value
         * @return Stable reading after debounce period
         */
        signed short getValue()
        {
            unsigned long now = millis();
            if (this->keepValueTill and (now < this->keepValueTill))
                return this->keepedValue;

            signed short value = TReader::getValue();

            if (!TReader::isValid())
                return this->keepedValue;

            if (value != this->keepedValue)
            {
                this->keepValueTill = now + tDebounceDelay;
                this->keepedValue = value;
            }
            return this->keepedValue;
        }

    private:
        unsigned long keepValueTill = 0;
        signed short keepedValue = 0;
    };

    /**
     * @brief Decorator that converts reading to binary based on level equality
     * @tparam TReader Underlying reader type
     * @tparam tActivatesOn Value that maps to active state (1)
     */
    template <class TReader, int tActivatesOn>
    class BinarizeEqDecor : public TReader
    {
    public:
        /**
         * @brief Constructs a BinarizeEqDecor
         * @param args Additional arguments passed to TReader constructor
         */
        template <typename... Args>
        BinarizeEqDecor(Args... args) : TReader(args...)
        {
        }

        /**
         * @brief Gets binary value based on equality check
         * @return 1 if value equals tActivatesOn, 0 otherwise
         */
        signed short getValue()
        {
            return TReader::getValue() == tActivatesOn;
        }
    };

    /**
     * @brief Decorator that converts analog reading to binary based on 'less than' threshold condition
     * @tparam TReader Underlying reader type
     * @tparam tThreshold threshold value
     */
    template <class TReader, int tThreshold>
    class BinarizeLtDecor : public TReader
    {
    public:
        /**
         * @brief Constructs a BinarizeLtDecor
         * @param args Additional arguments passed to TReader constructor
         */
        template <typename... Args>
        BinarizeLtDecor(Args... args) : TReader(args...)
        {
        }
        /**
         * @brief Gets binary value based on less than comparison
         * @return 1 if value <= threshold, 0 otherwise
         */
        signed short getValue()
        {
            if (TReader::getValue() < tThreshold)
                return 1;
            return 0;
        }
    };

    /**
     * @brief Decorator that converts analog reading to binary based on 'greater than' threshold condition
     * @tparam TReader Underlying reader type
     * @tparam tThreshold threshold value
     */
    template <class TReader, int tThreshold>
    class BinarizeGtDecor : public TReader
    {
    public:
        /**
         * @brief Constructs a BinarizeGtDecor
         * @param args Additional arguments passed to TReader constructor
         */
        template <typename... Args>
        BinarizeGtDecor(Args... args) : TReader(args...)
        {
        }
        /**
         * @brief Gets binary value based on greater than comparison
         * @return 1 if value >= threshold, 0 otherwise
         */
        signed short getValue()
        {
            if (TReader::getValue() > tThreshold)
                return 1;
            return 0;
        }
    };

    /**
     * @brief Decorator that quantizes analog readings to discrete levels
     * @tparam TReader Underlying reader type
     * @tparam tLevels threshold values for each level
     */
    template <class TReader, signed short... tLevels>
    class QuantizeDecor : public TReader
    {
        static_assert(sizeof...(tLevels) >= 2, "QuantizeDecor requires at least 2 levels");

    public:
        /**
         * @brief Constructs a QuantizeDecor
         * @param args Additional arguments passed to TReader constructor
         */
        template <typename... Args>
        QuantizeDecor(Args... args) : TReader(args...)
        {
        }
        /**
         * @brief Gets quantized level index
         * @return Level index (0 for no input, 1..n for specific levels)
         */
        signed short getValue()
        {
            signed short value = TReader::getValue() * 2;

            if (!TReader::isValid())
                return 0;

            unsigned char i = 1;
            for (i = 1; i < sizeof...(tLevels) - 1; i++)
                if (in_between(value, this->levels[i - 1] + this->levels[i], this->levels[i] + this->levels[i + 1]))
                    return i;
            if (in_between(value, this->levels[i - 1] + this->levels[i], 3 * this->levels[i] - this->levels[i - 1]))
                return i;
            return 0;
        }

        /**
         * @brief Gets Threshold value for a level
         * @param index Level index
         * @return threshold value
         */
        signed short getLevel(unsigned char index)
        {
            if ((index > sizeof...(tLevels)))
                return 0;
            return this->levels[index];
        }

    private:
        const signed short levels[sizeof...(tLevels)] = {tLevels...};
    };
}
