

# File evaButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaButton.h**](eva_button_8h.md)

[Go to the documentation of this file](eva_button_8h.md)


```C++
#ifndef EVABUTTON_H
#define EVABUTTON_H

#pragma once

#include "evaToggle.h"
#include "evaConstants.h"

namespace eva
{
    template <class READER>
    class Button : public Toggle<READER>
    {
    public:
        using Toggle<READER>::Toggle;

    private:
        void tick() override
        {
            if (this->isEnabled)
                return;

            unsigned char wasLevelCode = this->levelCode;
            this->levelCode = READER::getValue();

            if (this->pressTime and (millis() - this->pressTime) > 750)
            {
                this->notify(ON_LONGCLICK | this->levelCode);
                this->pressTime = 0;
            }

            if ((wasLevelCode > 0) and (wasLevelCode != this->levelCode)) // any_pos -> 0
            {
                if (this->pressTime and (millis() - this->pressTime < 750))
                    this->notify(ON_SHORTCLICK | wasLevelCode);
                this->notify(ON_RELEASE | wasLevelCode);
                this->pressTime = 0;
            }
            if ((wasLevelCode != this->levelCode) and (this->levelCode > 0)) // 0 -> any_pos
            {
                this->pressTime = millis();
                this->notify(ON_PRESS | this->levelCode);
            }
        }

    private:
        unsigned long pressTime;
    };

    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using PinMultiButton = Button<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;

    template <int PIN, int PIN_MODE, int ACTIVATES_ON> 
    using PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;

    template <int PIN>
    using PinPullUpButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;

};
#endif
```


