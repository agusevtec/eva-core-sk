#ifndef EVABUTTON_H
#define EVABUTTON_H

#pragma once

#include "evaToggle.h"
#include "evaConstants.h"

namespace eva
{
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
    class Button : public Toggle<READER>
    {
    public:
        using Toggle<READER>::Toggle;

    private:
        void tick() override
        {
            if (this->levelCode < 0)
                return;

            unsigned char wasLevelCode = this->levelCode;
            this->levelCode = READER::getValue();

            if (this->pressTime and (millis() - this->pressTime) > 750)
            {
                this->notify(ON_LONGCLICK, this->levelCode);
                this->pressTime = 0;
            }

            if ((wasLevelCode > 0) and (wasLevelCode != this->levelCode)) // any_pos -> 0
            {
                if (this->pressTime and (millis() - this->pressTime < 750))
                    this->notify(ON_SHORTCLICK , wasLevelCode);
                this->notify(ON_RELEASE, wasLevelCode);
                this->pressTime = 0;
            }
            if ((wasLevelCode != this->levelCode) and (this->levelCode > 0)) // 0 -> any_pos
            {
                this->pressTime = millis();
                this->notify(ON_PRESS , this->levelCode);
            }
        }

    private:
        unsigned long pressTime;
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
    using PinMultiButton = Button<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;

    /**
     * @brief Button connected directly to a digital pin
     * Includes stabilization and binarization decorators.
     * Debounces input and generates events based on button state changes.
     * Long click threshold is fixed at 750ms.
     *
     * @tparam PIN
     * @tparam PIN_MODE
     * @tparam ACTIVATES_ON - the level of a signal corresponding to the pressed state (LOW OR HIGH)
     * @return Button&
     */
    template <int PIN, int PIN_MODE, int ACTIVATES_ON> 
    using PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;

    template <int PIN>
    using PinPullUpButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;

};
#endif
