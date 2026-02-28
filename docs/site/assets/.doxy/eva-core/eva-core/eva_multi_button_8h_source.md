

# File evaMultiButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaMultiButton.h**](eva_multi_button_8h.md)

[Go to the documentation of this file](eva_multi_button_8h.md)


```C++
#ifndef EVAMULTIBUTTON_H
#define EVAMULTIBUTTON_H

#pragma once

#include "evaButton.h"

namespace eva
{
    struct MB_EVENTS
    {
        static const unsigned short ON_PRESS = 0x1000;
        static const unsigned short ON_RELEASE = 0x2000;
        static const unsigned short ON_SHORTCLICK = 0x4000;
        static const unsigned short ON_LONGCLICK = 0x8000;
    };

    template <class READER>
    class MultiButton: public Button<READER>
    {
    public:
        using Button<READER>::Button;

        signed short getValue()
        {
            return this->levelCode;
        }

    private:
        short tick() override
        {
            if ((this->encodedState & ENABLED) != ENABLED)
                return 0;
            unsigned char wasLevelCode = this->levelCode;
            this->levelCode = READER::getValue();

            if (this->pressTime and (millis() - this->pressTime) > 750)
            {
                notify(MB_EVENTS::ON_LONGCLICK | this->levelCode);
                this->pressTime = 0;
            }

            if ((wasLevelCode > 0) and (this->levelCode == 0)) // any -> 0
            {
                if (this->pressTime and (millis() - this->pressTime < 750))
                    notify(MB_EVENTS::ON_SHORTCLICK | wasLevelCode);
                notify(MB_EVENTS::ON_RELEASE | wasLevelCode);
                this->pressTime = 0;
            }
            if ((wasLevelCode == 0) and (this->levelCode > 0)) // 0 -> any
            {
                this->pressTime = millis();
                notify(MB_EVENTS::ON_PRESS | this->levelCode);
            }
            return 0;
        }

    private:
        unsigned char levelCode = 0;

    private:
        static const char ENABLED = 0x04;
    };

    template <int PIN, int PIN_MODE, signed short... LEVELS>
    using PinMultiButton = MultiButton<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
};
#endif
```


