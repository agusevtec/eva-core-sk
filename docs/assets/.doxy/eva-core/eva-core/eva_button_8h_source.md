

# File evaButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaButton.h**](eva_button_8h.md)

[Go to the documentation of this file](eva_button_8h.md)


```C++
#ifndef EVABUTTON_H
#define EVABUTTON_H

#pragma once

#include "evaSwitch.h"

namespace eva
{
    static const unsigned char ON_SHORTCLICK = 0x08;
    static const unsigned char ON_LONGCLICK = 0x10;

    template <class READER>
    class Button : public Switch<READER>
    {
    public:
        using Switch<READER>::Switch;

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
                if (this->pressTime and (millis() - this->pressTime) < 750)
                    this->notify(ON_SHORTCLICK, wasLevelCode);
                this->notify(ON_RELEASE, wasLevelCode);
                this->notify(ON_CHANGE, this->levelCode);
                this->pressTime = 0;
            }
            if ((wasLevelCode != this->levelCode) and (this->levelCode > 0)) // 0 -> any_pos
            {
                this->pressTime = millis();
                this->notify(ON_PRESS, this->levelCode);
                this->notify(ON_CHANGE, this->levelCode);
            }
        }

    private:
        unsigned long pressTime = 0;
    };

    template <int PIN, int PIN_MODE, int ACTIVATES_ON>
    using PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;

    template <int PIN>
    using PullUpButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;

    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using PinMultiButton = Button<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
#endif
```


