#ifndef EVAREADERDECORS_H
#define EVAREADERDECORS_H

#pragma once

#include <Arduino.h>

namespace eva
{
    static const unsigned short DEBOUNCE_DELAY = 120;

    inline static bool in_between(signed short x, signed short a, signed short b)
    {
        if ((a <= b) && (a <= x) && (x <= b))
            return true;
        if ((b <= a) && (b <= x) && (x <= a))
            return true;
        return false;
    }
    /**
     * @brief Decorator that stabilizes readings by requiring value to be stable for a period
     */
    template <class READER>
    class DebounceDecor : public READER
    {
    public:
        signed short getValue()
        {
            unsigned long now = millis();
            if (this->keepValueTill and (now < this->keepValueTill))
                return this->keepedValue;

            signed short value = READER::getValue();
            if (value != this->keepedValue)
            {
                this->keepValueTill = now + DEBOUNCE_DELAY;
                this->keepedValue = value;
            }
            return this->keepedValue;
        }

    private:
        unsigned long keepValueTill = 0;
        signed short keepedValue = 0;
    };

    /**
     * @brief Decorator that converts reading to binary based on level
     */
    template <class READER, int ACTIVATES_ON>
    class BinarizeEqDecor : public READER
    {
    public:
        signed short getValue()
        {
            return READER::getValue() == ACTIVATES_ON;
        }
    };

    /**
     * @brief Decorator that converts analog reading to binary based on 'less then' threshold condition
     */
    template <class READER, int THRESHOLD>
    class BinarizeLtDecor : public READER
    {
    public:
        signed short getValue()
        {
            if (READER::getValue() <= THRESHOLD)
                return 1;
            return 0;
        }
    };

    /**
     * @brief Decorator that converts analog reading to binary based on 'greater then' threshold condition
     */
    template <class READER, int THRESHOLD>
    class BinarizeGtDecor : public READER
    {
    public:
        signed short getValue()
        {
            if (READER::getValue() >= THRESHOLD)
                return 1;
            return 0;
        }
    };

    /**
     * @brief Decorator that quantizes analog readings to discrete levels
     */
    template <class READER, signed short... LEVELS>
    class QuantizeDecor : public READER
    {
        static_assert(sizeof...(LEVELS) >= 2, "QuantizeDecor requires at least 2 levels");

    public:
        /**
         * @brief Gets quantized level index
         * @return Level index (0 for no input, 1..n for specific levels)
         */
        signed short getValue()
        {
            signed short value = READER::getValue() * 2;
            unsigned char i;
            for (i = 1; i < sizeof...(LEVELS) - 1; i++)
                if (in_between(value, this->levels[i - 1] + this->levels[i], this->levels[i] + this->levels[i + 1]))
                    return i;
            if (in_between(value, this->levels[i - 1] + this->levels[i], 3 * this->levels[i] - this->levels[i - 1]))
                return i;
            return 0;
        }

        /**
         * @brief Gets threshold value for a level
         * @param index Level index
         * @return Threshold value
         */
        signed short getLevel(unsigned char index)
        {
            if ((index < 0) || (index > sizeof...(LEVELS)))
                return 0;
            return this->levels[index];
        }

    private:
        const signed short levels[sizeof...(LEVELS)] = {LEVELS...};
    };
}

#endif
