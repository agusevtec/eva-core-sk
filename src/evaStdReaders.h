#ifndef EVASTDREADERS_H
#define EVASTDREADERS_H
#include <Arduino.h>

#pragma once

namespace eva
{
    /**
     * @brief Reads digital pin value
     */
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
    };

    /**
     * @brief Reads analog pin value
     */
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
    };

};
#endif
