#ifndef EVASCROLLBUTTON_H
#define EVASCROLLBUTTON_H

#pragma once

#include "evaButton.h"
#include "evaCommon.h"

namespace eva
{
    static const unsigned short REPEAT_DELAY = 400;

    static const unsigned char ON_REPEATKEY = 0x40;

    /**
     * @brief Button with auto-repeat (typematic) functionality.
     *
     * This class extends Button by adding periodic ON_REPEAT events
     * while the button is held down. The naming reflects the primary
     * use case (keyboard-like repeat).
     *
     * - ON_CHANGE     - Any state change
     * - ON_PRESS      - Button becomes active (switch to active state)
     * - ON_RELEASE    - Button becomes inactive (switch to inactive state)
     * - ON_SHORTCLICK - Press and release within LONGPRESS_DELAY
     * - ON_LONGCLICK  - Press and hold longer than LONGPRESS_DELAY then release
     * - ON_LONGPRESS  - Press and hold longer than LONGPRESS_DELAY (no release)
     * - ON_REPEATKEY  - Periodic events while holding (after LONGPRESS_DELAY)
     *
     * @tparam READER Input reader type that returns numeric codes
     *                (0 = no button, >0 = button identifier)
     *
     * @see Button Base class for click detection
     */
    template <class READER>
    class ScrollButton : public Button<READER>
    {
    public:
        using Button<READER>::Button;

    private:
        
    void handleLongPress(unsigned long now)
        {
            Button<READER>::handleLongPress();
            this->notify(ON_REPEATKEY, this->levelCode);
            this->lastRepeatTime = max(1, now);
        }
        
        void handleDeactivating(unsigned char wasLevelCode, unsigned long now)
        {
            Button<READER>::handleDeactivating(wasLevelCode, now);
            this->lastRepeatTime = 0;
        }
        
        bool checkRepeatTime(unsigned long now)
        {
            return this->lastRepeatTime && (now - this->lastRepeatTime) > REPEAT_DELAY;
        }

        void handleRepeatTime(unsigned long now)
        {
            this->notify(ON_REPEATKEY, this->levelCode);
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

            if (this->(wasLevelCode))
                this->handleChanging();

            if (checkLongPress(now))
                handleLongPress(now);

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
     * @brief Digital pin key-button with debouncing and level normalization.
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
     * @brief Pull-up key-button (active LOW, connect to GND).
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
    using KeyPullUpButton = ScrollButton<BinarizeEqDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;

    /**
     * @brief Multiple key-buttons on a single ADC pin using resistor ladder.
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
    using KeyPinMultiButton = ScrollButton<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
#endif
