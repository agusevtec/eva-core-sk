

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

    template <class READER>
    class Switch : public READER, public Tickable
    {
    public:
        Switch()
        {
            enable(true);
        }

        Switch(IHandler *listener, unsigned short eventMask)
        {
            enable(true);
            setListener(listener, eventMask);
        }

        Switch *setListener(IHandler *listener, unsigned short eventMask)
        {
            this->listener = listener;
            this->curiosity = eventMask;
            return this;
        }

        Switch *enable(bool enabled)
        {
            if (this->levelCode < 0 && enabled)
                this->levelCode = 0;
            if (this->levelCode >= 0 && !enabled)
                this->levelCode = -1;
            return this;
        }

        signed short getValue()
        {
            if (this->levelCode > 0)
                return this->levelCode;
            return 0;
        }

    protected:
        void updateState()
        {
            this->levelCode = READER::getValue();
            if (this->levelCode < 0)
                this->levelCode = 0;
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
            updateState();
            
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

    template <int PIN, int PIN_MODE, int ACTIVE_LEVEL>
    using PinSwitch = Switch<BinarizeEqDecor<DebounceDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVE_LEVEL>>;

    template <int PIN>
    using PullupSwitch = PinSwitch<PIN, INPUT_PULLUP, LOW>;

    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using PinMultiSwitch = Switch<QuantizeDecor<DebounceDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
```


