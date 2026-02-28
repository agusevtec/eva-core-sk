#ifndef EVAREADERDECORS_H
#define EVAREADERDECORS_H

#pragma once

#include <Arduino.h>

#define SIGN(x) (((x) > 0) - ((x) < 0))

namespace eva
{
    /**
     * @brief Decorator that stabilizes readings by requiring value to be stable for a period
     */
    template <class READER>
    class StabilizeDecor : public READER
    {
    public:
        signed short getValue()
        {
            if (this->keepValueTill and (millis() < this->keepValueTill))
                return this->keepedValue;

            signed short value = READER::getValue();
            if (value != this->keepedValue)
            {
                this->keepValueTill = millis() + 120;
                this->keepedValue = value;
            }
            return this->keepedValue;
        }

    private:
        unsigned long keepValueTill = 0;
        signed short keepedValue = 0;
    };

    /**
     * @brief Decorator that converts analog reading to binary based on level
     */
    template <class READER, int LEVEL>
    class BinarizeDecor : public READER
    {
    public:
        signed short getValue()
        {
            return READER::getValue() == LEVEL;
        }
    };

    /**
     * @brief Decorator that normalizes readings to -1, 0, 1 based on threshold
     */
    template <class READER, int LEVEL>
    class PolarizeDecor : public READER
    {
    public:
        signed short getValue()
        {
            return constrain(READER::getValue() / LEVEL, -1, 1);
        }
    };

    /**
     * @brief Decorator that quantizes analog readings to discrete levels
     */
    template <class READER, signed short... LEVELS>
    class QuantizeDecor : public READER
    {
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
                if ((this->levels[i - 1] + this->levels[i]) <= value && value < (this->levels[i] + this->levels[i + 1]))
                    return i;
            if ((this->levels[i - 1] + this->levels[i] <= value) && (value < 3 * this->levels[i] - this->levels[i - 1]))
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
