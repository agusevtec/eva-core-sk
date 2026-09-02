

# File evaReaderDecors.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaReaderDecors.h**](eva_reader_decors_8h.md)

[Go to the documentation of this file](eva_reader_decors_8h.md)


```C++
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
    template <class TReader>
    class DebounceDecor : public TReader
    {
    public:
        template <typename... Args>
        DebounceDecor(Args... args) : TReader(args...)
        {
        }
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
                this->keepValueTill = now + DEBOUNCE_DELAY;
                this->keepedValue = value;
            }
            return this->keepedValue;
        }

    private:
        unsigned long keepValueTill = 0;
        signed short keepedValue = 0;
    };

    template <class TReader, int tActivatesOn>
    class BinarizeEqDecor : public TReader
    {
    public:
        template <typename... Args>
        BinarizeEqDecor(Args... args) : TReader(args...)
        {
        }

        signed short getValue()
        {
            return TReader::getValue() == tActivatesOn;
        }
    };

    template <class TReader, int THRESHOLD>
    class BinarizeLtDecor : public TReader
    {
    public:
        template <typename... Args>
        BinarizeLtDecor(Args... args) : TReader(args...)
        {
        }
        signed short getValue()
        {
            if (TReader::getValue() <= THRESHOLD)
                return 1;
            return 0;
        }
    };

    template <class TReader, int THRESHOLD>
    class BinarizeGtDecor : public TReader
    {
    public:
        template <typename... Args>
        BinarizeGtDecor(Args... args) : TReader(args...)
        {
        }
        signed short getValue()
        {
            if (TReader::getValue() >= THRESHOLD)
                return 1;
            return 0;
        }
    };

    template <class TReader, signed short... tLevels>
    class QuantizeDecor : public TReader
    {
        static_assert(sizeof...(tLevels) >= 2, "QuantizeDecor requires at least 2 levels");

    public:
        template <typename... Args>
        QuantizeDecor(Args... args) : TReader(args...)
        {
        }
        signed short getValue()
        {
            signed short value = TReader::getValue() * 2;

            if (!TReader::isValid())
                return 0;

            unsigned char i;
            for (i = 1; i < sizeof...(tLevels) - 1; i++)
                if (in_between(value, this->levels[i - 1] + this->levels[i], this->levels[i] + this->levels[i + 1]))
                    return i;
            if (in_between(value, this->levels[i - 1] + this->levels[i], 3 * this->levels[i] - this->levels[i - 1]))
                return i;
            return 0;
        }

        signed short getLevel(unsigned char index)
        {
            if ((index < 0) || (index > sizeof...(tLevels)))
                return 0;
            return this->levels[index];
        }

    private:
        const signed short levels[sizeof...(tLevels)] = {tLevels...};
    };
}
```


