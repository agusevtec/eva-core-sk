

# File evaButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaButton.h**](eva_button_8h.md)

[Go to the documentation of this file](eva_button_8h.md)


```C++
#ifndef EVABUTTON_H
#define EVABUTTON_H

#pragma once

#include "evaSwitch.h"
#include "evaCommon.h"

namespace eva
{
    static const unsigned char ON_SHORTCLICK = 0x08;
    static const unsigned char ON_LONGCLICK = 0x10;
    static const unsigned char ON_LONGPRESS = 0x20;

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

    template <int PIN, int PIN_MODE, int ACTIVATES_ON>
    using PinButton = Button<BinarizeEqDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;

    template <int PIN>
    using PullUpButton = Button<BinarizeEqDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;

    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using PinMultiButton = Button<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
#endif
```


