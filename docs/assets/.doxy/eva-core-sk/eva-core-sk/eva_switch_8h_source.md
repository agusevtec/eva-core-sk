

# File evaSwitch.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaSwitch.h**](eva_switch_8h.md)

[Go to the documentation of this file](eva_switch_8h.md)


```C++
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

    template <class TReader>
    class Switch : public TReader, public Tickable
    {
    public:
        template <typename... Args>
        Switch(IHandler *listener = nullptr, unsigned char eventMask = 0, Args... args) : TReader(args...)
        {
            enable(true);
            setListener(listener, eventMask);
        }

        Switch *setListener(IHandler *listener, unsigned char eventMask)
        {
            this->listener = listener;
            this->eventMask = eventMask & 0x7F;
            return this;
        }

        Switch *enable(bool enabled)
        {
            if (!enabled)
                this->levelCode = 0;

            this->enabled = enabled;
            return this;
        }

        bool isEnabled() const
        {
            return this->enabled;
        }

        signed short getValue()
        {
            return this->enabled ? this->levelCode : 0;
        }

    protected:
        bool updateState()
        {
            if (!TReader::isValid())
            {
                this->levelCode = 0;
                return false;
            }

            signed short rawVal = TReader::getValue();
            this->levelCode = ((0 <= rawVal) && (rawVal <= 255)) ? rawVal : 0;
            return true;
        }

        bool checkChanging(unsigned char wasLevelCode)
        {
            return (wasLevelCode != this->levelCode);
        }

        bool checkDeactivating(unsigned char wasLevelCode)
        {
            return (wasLevelCode > 0) && (wasLevelCode != this->levelCode);
        }

        bool checkActivating(unsigned char wasLevelCode)
        {
            return (wasLevelCode != this->levelCode) && (this->levelCode > 0);
        }

        void notify(unsigned short eventType, signed short eventCode)
        {
            if (this->listener)
                if (this->eventMask & eventType)
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
            if (!isEnabled())
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
        unsigned char eventMask : 7;
        bool enabled : 1;
        unsigned char levelCode = 0;
        IHandler *listener = nullptr;
    };

    template <int tPin, int tPinMode, int ACTIVE_LEVEL>
    using PinSwitch = Switch<BinarizeEqDecor<DebounceDecor<DigitalPinReader<tPin, tPinMode>>, ACTIVE_LEVEL>>;

    template <int tPin>
    using PullUpSwitch = PinSwitch<tPin, INPUT_PULLUP, LOW>;

    template <int tPin, int tPinMode, signed short... tLevels>
    using PinMultiSwitch = Switch<QuantizeDecor<DebounceDecor<AnalogPinReader<tPin, tPinMode>>, tLevels...>>;
};
```


