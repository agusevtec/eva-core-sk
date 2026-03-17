

# File evaScrollButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaScrollButton.h**](eva_scroll_button_8h.md)

[Go to the documentation of this file](eva_scroll_button_8h.md)


```C++
#ifndef EVASCROLLBUTTON_H
#define EVASCROLLBUTTON_H

#pragma once

#include "evaButton.h"
#include "evaCommon.h"

namespace eva
{
    static const unsigned short REPEAT_DELAY = 400;

    static const unsigned char ON_REPEATKEY = 0x40;

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
            return (this->lastRepeatTime) && ((now - this->lastRepeatTime) > REPEAT_DELAY);
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

    template <int PIN, int PIN_MODE, int ACTIVATES_ON>
    using KeyPinButton = Button<BinarizeEqDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;

    template <int PIN>
    using KeyPullUpButton = ScrollButton<BinarizeEqDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;

    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using KeyPinMultiButton = ScrollButton<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
#endif
```


