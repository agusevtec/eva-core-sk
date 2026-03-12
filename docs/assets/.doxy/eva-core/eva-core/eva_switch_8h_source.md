

# File evaSwitch.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaSwitch.h**](eva_switch_8h.md)

[Go to the documentation of this file](eva_switch_8h.md)


```C++
#ifndef EVATOGGLE_H
#define EVATOGGLE_H
#pragma once

#include "evaTickable.h"
#include "evaHandler.h"
#include "evaStdReaders.h"
#include "evaReaderDecors.h"

namespace eva
{
    static const unsigned char ON_CHANGE = 0x1;
    static const unsigned char ON_PRESS = 0x02;
    static const unsigned char ON_RELEASE = 0x04;

    static const unsigned char ON_ACTIVE = ON_PRESS;
    static const unsigned char ON_INACTIVE = ON_RELEASE;

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
        void tick() override
        {
            if (this->levelCode < 0)
                return;

            unsigned char wasLevelCode = this->levelCode;
            this->levelCode = READER::getValue();
            
            if ((wasLevelCode > 0) and (wasLevelCode != this->levelCode)) // active -> inactive or different state
            {
                this->notify(ON_RELEASE, wasLevelCode);
                this->notify(ON_CHANGE, wasLevelCode);
            }
            if ((wasLevelCode != this->levelCode) and (this->levelCode > 0)) // inactive or different -> active
            {
                this->notify(ON_PRESS, this->levelCode);
                this->notify(ON_CHANGE, this->levelCode);
            }
        }

        void notify(unsigned short eventType, signed short eventCode)
        {
            if (this->listener)
                if (this->curiosity & eventType)
                    this->listener->invoke(this, {eventType, eventCode});
        }

    protected:
        unsigned char curiosity = 0;
        signed char levelCode = 0;
        IHandler *listener = nullptr;
    };

    template <int PIN, int PIN_MODE, int ACTIVE_LEVEL>
    using PinSwitch = Switch<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVE_LEVEL>>;

    template <int PIN>
    using PullupSwitch = PinSwitch<PIN, INPUT_PULLUP, LOW>;

    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using PinMultiSwitch = Switch<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};

#endif
```


