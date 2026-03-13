#ifndef EVAKEYBUTTON_H
#define EVAKEYBUTTON_H

#pragma once

#include "evaButton.h"
#include "evaCommon.h"

namespace eva
{
    static const unsigned char ON_REPEAT = 0x40;

    /**
     * @brief Button with press/release and click detection.
     *
     * Extends Switch with timing-based events: short click and long click.
     * For basic active/inactive behavior, use Switch directly.
     *
     * The class works with any reader that returns numeric codes:
     * - 0 means "no button pressed"
     * - Positive values identify specific buttons
     *
     * Events include both the event type and the button code in argsMask,
     * allowing identification of which specific button triggered the event:
     * in addition to Switch - ON_SHORTCLICK, ON_LONGCLICK, ON_LONGPRESS.
     *
     * Long click threshold is fixed at 750ms.
     *
     * @tparam READER Input reader type that returns numeric codes
     *                (0 = no button, >0 = button identifier)
     *
     * @see Switch Base class for active/inactive state management
     * @see PinButton Digital pin button with debouncing (typical use)
     * @see PullUpButton Pull-up button convenience alias
     * @see PinMultiButton Multiple buttons on one ADC pin
     */
    template <class READER>
    class KeyButton : public Button<READER>
    {
    public:
        using Button<READER>::Button;

    private:
        void handleLongPress(unsigned long now)
        {
            Button<Reader>::handleLongpress();
            this->notify(ON_REPEAT, this->levelCode);
            this->lastRepeatTime = max(1, now);
        }
        void handleDeactivating(unsigned char wasLevelCode, unsigned long now)
        {
            Button<READER>::handleDeactivating(wasLevelCode);
            this->lastRepeatTime = 0;
        }
        bool checkRepeatTime(unsigned long now)
        {
            return this->lastRepeatTime && (now - this->lastRepeatTime) > REPEAT_DELAY;
        }
        void handleRepeatTime(unsigned long now)
        {
            this->notify(ON_REPEAT, this->levelCode);
            this->lastRepeatTime = max(1, now);
        }

    private:
        void tick() override
        {
            if (this->levelCode < 0)
                return;

            unsigned long now = millis();
            unsigned char wasLevelCode = this->levelCode;
            this->updateState();

            if (checkLongPress(now))
                handleLongPress();

            if (checkRepeatTime(now))
                handleRepeatTime(now);

            if (this->checkDeactivating(wasLevelCode))
                handleDeactivating(wasLevelCode, now);

            if (this->checkActivating(wasLevelCode))
                this->handleActivating(now);
        }

    private:
        unsigned long lastRepeatTime = 0;
    };

    /**
     * @brief Digital pin button with debouncing and level normalization.
     *
     * Combines:
     * - DigitalPinReader for raw pin reading
     * - StabilizeDecor for debouncing (120ms stability)
     * - BinarizeEqDecor for mapping to active/inactive based on specified level
     *
     * Long click threshold is fixed at 750ms.
     *
     * @tparam PIN Arduino pin number
     * @tparam PIN_MODE Pin mode (INPUT, INPUT_PULLUP, etc.)
     * @tparam ACTIVATES_ON Level that means "pressed" (LOW or HIGH)
     */
    template <int PIN, int PIN_MODE, int ACTIVATES_ON>
    using KeyPinButton = Button<BinarizeEqDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;

    /**
     * @brief Pull-up button (active LOW, connect to GND).
     *
     * Convenience alias for the most common Arduino button wiring:
     * - Pin set to INPUT_PULLUP
     * - Button connects pin to GND when pressed
     *
     * Generates all button events with proper debouncing.
     *
     * @tparam PIN Arduino pin number
     */
    template <int PIN>
    using KeyPullUpButton = KeyButton<BinarizeEqDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;

    /**
     * @brief Multiple buttons on a single ADC pin using resistor ladder.
     *
     * Hardware connection:
     * ```
     *    ADC Pin  -----+--R1--+--R2--+-- ... -Rn-+
     *   (analog in)    |      |      |           |
     *                   \      \      \           \
     *                  |      |      |           |
     *      GND    -----+------+------+-- ... ----+
     * ```
     *
     * Each button produces a different ADC value when pressed. The
     * QuantizeDecor maps these values to discrete button codes (1, 2, 3...).
     * StabilizeDecor provides debouncing.
     *
     * Generates standard button events for each button, with the button
     * number encoded in the event mask.
     *
     * @tparam PIN Arduino analog pin number
     * @tparam PIN_MODE Pin mode (usually INPUT)
     * @tparam LEVELS Threshold values for each button (expected ADC readings)
     *
     * @see PinMultiSwitch For use cases without click detection
     */
    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using KeyPinMultiButton = KeyButton<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
#endif
