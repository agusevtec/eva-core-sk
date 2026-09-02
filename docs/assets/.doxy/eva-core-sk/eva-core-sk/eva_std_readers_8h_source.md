

# File evaStdReaders.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaStdReaders.h**](eva_std_readers_8h.md)

[Go to the documentation of this file](eva_std_readers_8h.md)


```C++
#pragma once

#include <Arduino.h>

namespace eva
{
    template <int tPin, int tPinMode>
    class DigitalPinReader
    {
    public:
        DigitalPinReader()
        {
            pinMode(tPin, tPinMode);
        }

        signed short getValue()
        {
            return digitalRead(tPin);
        }
        bool isValid()
        {
            return true;
        }
    };

    template <int tPin, int tPinMode>
    class AnalogPinReader
    {
    public:
        AnalogPinReader()
        {
            pinMode(tPin, tPinMode);
        }

        signed short getValue()
        {
            return analogRead(tPin);
        }
        
        bool isValid()
        {
            return true;
        }
    };

    class AnalogMutablePinReader
    {
    public:
        AnalogMutablePinReader(uint8_t aPin, uint8_t aMode);

        signed short getValue();

        bool isValid();

    private:
        uint8_t mPin;
    };

    class DigitalMutablePinReader
    {
    public:
        DigitalMutablePinReader(uint8_t aPin, uint8_t aMode);

        signed short getValue();

        bool isValid();

    private:
        uint8_t mPin;
    };

};
```


