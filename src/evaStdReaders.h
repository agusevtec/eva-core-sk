#pragma once

#include <Arduino.h>

namespace eva
{
    /**
     * @brief Reads digital pin value
     * @tparam tPin Arduino pin number
     * @tparam tPinMode Pin mode (INPUT, INPUT_PULLUP, etc.)
     */
    template <int tPin, int tPinMode>
    class DigitalPinReader
    {
    public:
        /**
         * @brief Constructs a DigitalPinReader and configures pin mode
         */
        DigitalPinReader()
        {
            pinMode(tPin, tPinMode);
        }

        /**
         * @brief Reads digital pin value
         * @return HIGH or LOW
         */
        signed short getValue()
        {
            return digitalRead(tPin);
        }
        /**
         * @brief Checks if reader is valid
         * @return Always true for digital pin reader
         */
        bool isValid()
        {
            return true;
        }
    };

    /**
     * @brief Reads analog pin value
     * @tparam tPin Arduino analog pin number
     * @tparam tPinMode Pin mode (usually INPUT)
     */
    template <int tPin, int tPinMode>
    class AnalogPinReader
    {
    public:
        /**
         * @brief Constructs an AnalogPinReader and configures pin mode
         */
        AnalogPinReader()
        {
            pinMode(tPin, tPinMode);
        }

        /**
         * @brief Reads analog pin value
         * @return ADC reading (0-1023)
         */
        signed short getValue()
        {
            return analogRead(tPin);
        }
        
        /**
         * @brief Checks if reader is valid
         * @return Always true for analog pin reader
         */
        bool isValid()
        {
            return true;
        }
    };

    /**
     * @brief Reads analog pin value with runtime pin configuration
     */
    class AnalogMutablePinReader
    {
    public:
        /**
         * @brief Constructs an AnalogMutablePinReader and configures pin
         * @param aPin Arduino analog pin number
         * @param aMode Pin mode
         */
        AnalogMutablePinReader(uint8_t aPin, uint8_t aMode);

        /**
         * @brief Reads analog pin value
         * @return ADC reading (0-1023)
         */
        signed short getValue();

        /**
         * @brief Checks if reader is valid
         * @return Always true
         */
        bool isValid();

    private:
        uint8_t mPin;
    };

    /**
     * @brief Reads digital pin value with runtime pin configuration
     */
    class DigitalMutablePinReader
    {
    public:
        /**
         * @brief Constructs a DigitalMutablePinReader and configures pin
         * @param aPin Arduino digital pin number
         * @param aMode Pin mode
         */
        DigitalMutablePinReader(uint8_t aPin, uint8_t aMode);

        /**
         * @brief Reads digital pin value
         * @return HIGH or LOW
         */
        signed short getValue();

        /**
         * @brief Checks if reader is valid
         * @return Always true
         */
        bool isValid();

    private:
        uint8_t mPin;
    };

};
