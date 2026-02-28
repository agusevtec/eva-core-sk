#ifndef EVAMULTIBUTTON_H
#define EVAMULTIBUTTON_H

#pragma once

#include "evaButton.h"

namespace eva
{
    struct MB_EVENTS
    {
        static const unsigned short ON_PRESS = 0x1000;
        static const unsigned short ON_RELEASE = 0x2000;
        static const unsigned short ON_SHORTCLICK = 0x4000;
        static const unsigned short ON_LONGCLICK = 0x8000;
    };

    /**
     * @brief Multi-state button that identifies which button was pressed via level code
     *
     * Generic button class that works with any multi-valued input source.
     * The input reader can return different numeric codes representing different
     * states. Typical applications:
     * -# Resistor ladder buttons on single ADC pin
     * -# Custom encoding schemes
     * -# Multiplexed inputs
     *
     * Events include the level code in argsMask, allowing identification of
     * which specific button triggered the event.
     * Long click threshold is fixed at 750ms.
     *
     * @tparam READER Input reader type that returns numeric codes (0 = no button, >0 = button index)
     */
    template <class READER>
    class MultiButton: public Button<READER>
    {
    public:
        using Button<READER>::Button;

        /**
         * @brief Gets the button level code identifying which button was pressed
         * @return Level code (0 for no button, >0 for specific button)
         */
        signed short getValue()
        {
            return this->levelCode;
        }

    private:
        short tick() override
        {
            if ((this->encodedState & ENABLED) != ENABLED)
                return 0;
            unsigned char wasLevelCode = this->levelCode;
            this->levelCode = READER::getValue();

            if (this->pressTime and (millis() - this->pressTime) > 750)
            {
                notify(MB_EVENTS::ON_LONGCLICK | this->levelCode);
                this->pressTime = 0;
            }

            if ((wasLevelCode > 0) and (this->levelCode == 0)) // any -> 0
            {
                if (this->pressTime and (millis() - this->pressTime < 750))
                    notify(MB_EVENTS::ON_SHORTCLICK | wasLevelCode);
                notify(MB_EVENTS::ON_RELEASE | wasLevelCode);
                this->pressTime = 0;
            }
            if ((wasLevelCode == 0) and (this->levelCode > 0)) // 0 -> any
            {
                this->pressTime = millis();
                notify(MB_EVENTS::ON_PRESS | this->levelCode);
            }
            return 0;
        }

    private:
        unsigned char levelCode = 0;

    private:
        static const char ENABLED = 0x04;
    };

    /**
     * @brief Multiple buttons on single ADC pin using resistor ladder
     *
     * Hardware connection:
     *    ADC IN   -----+--R1--+--R2--+-- ... -Rn-+
     *   (pullup)       |      |      |           |
     *                   \      \      \           \
     *                  |      |      |           |
     *      GND    -----+------+------+-- ... ----+
     *
     * Each button produces different ADC value which is mapped to levelCode.
     * Debounces input and generates events based on button state changes.
     * @tparam PIN Arduino analog pin number
     * @tparam PIN_MODE Pin mode (usually INPUT)
     * @tparam LEVELS Threshold values for different buttons
     */
    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using PinMultiButton = MultiButton<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
#endif
