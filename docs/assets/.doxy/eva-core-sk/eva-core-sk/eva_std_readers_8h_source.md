

# File evaStdReaders.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaStdReaders.h**](eva_std_readers_8h.md)

[Go to the documentation of this file](eva_std_readers_8h.md)


```C++
#ifndef EVASTDREADERS_H
#define EVASTDREADERS_H
#include <Arduino.h>

#pragma once

namespace eva
{
    template <int PIN, int PIN_MODE>
    class DigitalPinReader
    {
    public:
        DigitalPinReader()
        {
            pinMode(PIN, PIN_MODE);
        }

        signed short getValue()
        {
            return digitalRead(PIN);
        }
        bool isValid()
        {
            return true;
        }
    };

    template <int PIN, int PIN_MODE>
    class AnalogPinReader
    {
    public:
        AnalogPinReader()
        {
            pinMode(PIN, PIN_MODE);
        }

        signed short getValue()
        {
            return analogRead(PIN);
        }
        bool isValid()
        {
            return true;
        }
    };

};
#endif
```


