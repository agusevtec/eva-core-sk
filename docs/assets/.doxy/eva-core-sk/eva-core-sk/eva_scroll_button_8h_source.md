

# File evaScrollButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaScrollButton.h**](eva_scroll_button_8h.md)

[Go to the documentation of this file](eva_scroll_button_8h.md)


```C++
#pragma once

#include "evaButton.h"

namespace eva
{
    static const unsigned short REPEAT_DELAY = 300;

    static const unsigned char ON_REPEATKEY = 0x40;

    template <class TReader>
    class ScrollButton : public Button<TReader>
    {
    public:
        using Button<TReader>::Button;

        ScrollButton *enable(bool enabled)
        {
            if (!enabled)
                this->lastRepeatTime = 0;

            Button<TReader>::enable(enabled);
            return this;
        }

    protected:
        void handleLongPress(unsigned long now)
        {
            Button<TReader>::handleLongPress();
            this->notify(ON_REPEATKEY, this->levelCode);
            this->lastRepeatTime = (now == 0) ? 1 : now;
        }

        void handleDeactivating(unsigned char wasLevelCode, unsigned long now)
        {
            Button<TReader>::handleDeactivating(wasLevelCode, now);
            this->lastRepeatTime = 0;
        }

        bool checkRepeatTime(unsigned long now)
        {
            return (this->lastRepeatTime > 0) && ((now - this->lastRepeatTime) > REPEAT_DELAY);
        }

        void handleRepeatTime(unsigned long now)
        {
            this->notify(ON_REPEATKEY, this->levelCode);
            this->lastRepeatTime = (now == 0) ? 1 : now;
        }

    private:
        void tick() override
        {
            if (!this->isEnabled())
                return;

            unsigned long now = millis();
            unsigned char wasLevelCode = this->levelCode;
            if (!this->updateState())
                return;

            if (this->checkChanging(wasLevelCode))
                this->handleChanging();

            if (this->checkDeactivating(wasLevelCode))
                handleDeactivating(wasLevelCode, now);

            if (this->checkActivating(wasLevelCode))
                this->handleActivating(now);

            if (this->checkLongPress(now))
                handleLongPress(now);

            if (checkRepeatTime(now))
                handleRepeatTime(now);
        }

    protected:
        unsigned long lastRepeatTime = 0;
    };

    template <int tPin, int tPinMode, int tActivatesOn>
    using PinScrollButton = ScrollButton<BinarizeEqDecor<DebounceDecor<DigitalPinReader<tPin, tPinMode>>, tActivatesOn>>;

    template <int tPin>
    using PullUpScrollButton = ScrollButton<BinarizeEqDecor<DebounceDecor<DigitalPinReader<tPin, INPUT_PULLUP>>, LOW>>;

    template <int tPin, int tPinMode, signed short... tLevels>
    using PinMultiScrollButton = ScrollButton<QuantizeDecor<DebounceDecor<AnalogPinReader<tPin, tPinMode>>, tLevels...>>;
};
```


