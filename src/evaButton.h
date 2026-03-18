#ifndef EVABUTTON_H
#define EVABUTTON_H

#pragma once

#include "evaSwitch.h"

namespace eva
{
    static const unsigned short LONGPRESS_DELAY = 750;

    static const unsigned char ON_SHORTCLICK = 0x08;
    static const unsigned char ON_LONGCLICK = 0x10;
    static const unsigned char ON_LONGPRESS = 0x20;

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
    class Button : public Switch<READER>
    {
    public:
        using Switch<READER>::Switch;

    protected:
        bool checkLongPress(unsigned long now)
        {
           return this->pressTime && (now - this->pressTime) > LONGPRESS_DELAY; 
        }

        void handleLongPress()
        {
            this->notify(ON_LONGPRESS, this->levelCode);
            this->pressTime = 0;
        }

        void handleDeactivating(unsigned char wasLevelCode, unsigned long now)
        {
            Switch<READER>::handleDeactivating(wasLevelCode);
            if (this->pressTime)
                this->notify(((now - this->pressTime) <= LONGPRESS_DELAY) ? ON_SHORTCLICK : ON_LONGCLICK, wasLevelCode);
            this->pressTime = 0;
        }

        void handleActivating(unsigned long now)
        {
            Switch<READER>::handleActivating();
            this->pressTime = now;
        }


    private:
        void tick() override
        {
            if (this->levelCode < 0)
                return;

            unsigned long now = millis();
            unsigned char wasLevelCode = this->levelCode;
            this->updateState();

            if (this->checkChanging(wasLevelCode))
                this->handleChanging();

            if (checkLongPress(now))
                handleLongPress();

            if (this->checkDeactivating(wasLevelCode))
                handleDeactivating(wasLevelCode, now);

            if (this->checkActivating(wasLevelCode))
                handleActivating(now);
        }

    protected:
        unsigned long pressTime = 0;
    };

    /**
     * @brief Digital pin button with debouncing and level normalization.
     *
     * Combines:
     * - DigitalPinReader for raw pin reading
     * - DebounceDecor for debouncing (120ms stability)
     * - BinarizeEqDecor for mapping to active/inactive based on specified level
     *
     * Long click threshold is fixed at 750ms.
     *
     * @tparam PIN Arduino pin number
     * @tparam PIN_MODE Pin mode (INPUT, INPUT_PULLUP, etc.)
     * @tparam ACTIVATES_ON Level that means "pressed" (LOW or HIGH)
     */
    template <int PIN, int PIN_MODE, int ACTIVATES_ON>
    using PinButton = Button<BinarizeEqDecor<DebounceDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;

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
    using PullUpButton = Button<BinarizeEqDecor<DebounceDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;

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
     * DebounceDecor provides debouncing.
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
    using PinMultiButton = Button<QuantizeDecor<DebounceDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
#endif
