#pragma once

#include "evaTickable.h"
#include "evaHandler.h"
#include "evaStdReaders.h"
#include "evaReaderDecors.h"

namespace eva
{
    static const unsigned char ON_PRESS = 0x01;
    static const unsigned char ON_RELEASE = 0x02;

    static const unsigned char ON_CHANGE = 0x04;

    /**
     * @brief Universal switch/button class for multi-valued input sources.
     *
     * This class handles both switch and button behavior within the same component.
     * The difference is purely semantic:
     * -# React to ON_CHANGE for switch-like behavior
     * -# React to ON_PRESS/ON_RELEASE for button-like behavior
     *
     * Typical applications:
     * -# Simple on/off switches (binary reader)
     * -# Push buttons with press/release detection
     * -# Resistor ladder buttons on a single ADC pin
     * -# Custom encoding schemes (rotary encoders, keypads)
     * -# Multiplexed inputs
     *
     * Events include both the event type and the level code in argsMask,
     * allowing identification of which specific input triggered the event.
     *
     * @tparam TReader Input reader type that returns numeric codes
     *                (0 = inactive, >0 = active state identifier)
     * @see PinSwitch Digital pin switches with debouncing (typical use)
     * @see PullUpSwitch Pull-up switches convenience alias
     * @see PinMultiSwitch Multiple switches on one ADC pin
     */
    template <class TReader>
    class Switch : public TReader, public Tickable
    {
    public:
        /**
         * @brief Constructs a Switch
         * @param listener Handler to receive events
         * @param eventMask Bitmask of events to listen for (ON_PRESS, ON_RELEASE, ON_CHANGE)
         * @param args Additional arguments passed to TReader constructor
         */
        template <typename... Args>
        Switch(IHandler *listener = nullptr, unsigned short eventMask = 0, Args... args) : TReader(args...)
        {
            enable(true);
            setListener(listener, eventMask);
        }

        /**
         * @brief Sets the event listener for this switch.
         *
         * @param listener Callback object implementing IHandler
         * @param eventMask Bitmask of events to listen for (ON_PRESS, ON_RELEASE, ON_CHANGE)
         * @return Pointer to this for method chaining
         */
        Switch *setListener(IHandler *listener, unsigned short eventMask)
        {
            this->listener = listener;
            this->curiosity = eventMask;
            return this;
        }

        /**
         * @brief Enables or disables the switch.
         *
         * When disabled, the switch stops generating events.
         *
         * @param enabled True to enable, false to disable
         * @return Pointer to this for method chaining
         */
        Switch *enable(bool enabled)
        {
            if (this->levelCode < 0 && enabled)
                this->levelCode = 0;
            if (this->levelCode >= 0 && !enabled)
                this->levelCode = -1;
            return this;
        }

        /**
         * @brief Gets the current level code.
         *
         * @return Level code (0 for inactive, positive value for active state)
         */
        signed short getValue()
        {
            if (this->levelCode > 0)
                return this->levelCode;
            return 0;
        }

    protected:
        bool updateState()
        {
            this->levelCode = TReader::getValue();
            if (!TReader::isValid())
                return false;

            if (this->levelCode < 0)
                this->levelCode = 0;

            return true;
        }

        bool checkChanging(unsigned char wasLevelCode)
        {
            return (wasLevelCode != this->levelCode);
        }

        /// active -> inactive or different state
        bool checkDeactivating(unsigned char wasLevelCode)
        {
            return (wasLevelCode > 0) && (wasLevelCode != this->levelCode);
        }

        /// inactive or different -> active
        bool checkActivating(unsigned char wasLevelCode)
        {
            return (wasLevelCode != this->levelCode) && (this->levelCode > 0);
        }

        void notify(unsigned short eventType, signed short eventCode)
        {
            if (this->listener)
                if (this->curiosity & eventType)
                    this->listener->invoke(this, {eventType, eventCode});
        }

        void handleChanging()
        {
            this->notify(ON_CHANGE, this->levelCode);
        }

        void handleDeactivating(unsigned char wasLevelCode)
        {
            this->notify(ON_RELEASE, wasLevelCode);
        }

        void handleActivating()
        {
            this->notify(ON_PRESS, this->levelCode);
        }

    private:
        void tick() override
        {
            if (this->levelCode < 0)
                return;

            unsigned char wasLevelCode = this->levelCode;
            if (!updateState())
                return;

            if (checkChanging(wasLevelCode))
                handleChanging();

            if (checkDeactivating(wasLevelCode))
                handleDeactivating(wasLevelCode);

            if (checkActivating(wasLevelCode))
                handleActivating();
        }

    protected:
        unsigned char curiosity = 0;
        signed char levelCode = 0;
        IHandler *listener = nullptr;
    };

    /**
     * @brief Digital pin switch with debouncing and level normalization.
     *
     * Combines:
     * - DigitalPinReader for raw pin reading
     * - DebounceDecor for debouncing (120ms stability)
     * - BinarizeEqDecor for mapping to active/inactive based on specified level
     *
     * @tparam tPin Arduino pin number
     * @tparam tPinMode Pin mode (INPUT, INPUT_PULLUP, etc.)
     * @tparam ACTIVE_LEVEL Level that means active (LOW or HIGH)
     */
    template <int tPin, int tPinMode, int ACTIVE_LEVEL>
    using PinSwitch = Switch<BinarizeEqDecor<DebounceDecor<DigitalPinReader<tPin, tPinMode>>, ACTIVE_LEVEL>>;

    /**
     * @brief Pull-up switch (active LOW, connect to GND).
     *
     * Convenience alias for the most common Arduino switch wiring:
     * - Pin set to INPUT_PULLUP
     * - Switch connects pin to GND when pressed
     *
     * @tparam tPin Arduino pin number
     */
    template <int tPin>
    using PullupSwitch = PinSwitch<tPin, INPUT_PULLUP, LOW>;

    /**
     * @brief Multiple switches on a single ADC pin using resistor ladder.
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
     * Each switch produces a different ADC value when activated. The
     * QuantizeDecor maps these values to discrete level codes (1, 2, 3...).
     * DebounceDecor provides debouncing.
     *
     * @tparam tPin Arduino analog pin number
     * @tparam tPinMode Pin mode (usually INPUT)
     * @tparam tLevels Threshold values for each switch (expected ADC readings)
     */
    template <int tPin, int tPinMode, signed short... tLevels>
    using PinMultiSwitch = Switch<QuantizeDecor<DebounceDecor<AnalogPinReader<tPin, tPinMode>>, tLevels...>>;
};
