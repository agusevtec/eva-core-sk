#ifndef EVASTDREADERS_H
#define EVASTDREADERS_H
#include <Arduino.h>

#pragma once

namespace eva
{
    template <int PIN, int PINMODE>
    class DigitalPinReader
    {
    public:
        DigitalPinReader()
        {
            pinMode(PIN, PINMODE);
        }

        signed short getValue()
        {
            return digitalRead(PIN);
        }
    };

    template <int PIN, int PINMODE>
    class AnalogPinReader
    {
    public:
        AnalogPinReader()
        {
            pinMode(PIN, PINMODE);
        }

        signed short getValue()
        {
            return analogRead(PIN);
        }
    };

};
#endif
