

# File evaToggle.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaToggle.h**](eva_toggle_8h.md)

[Go to the documentation of this file](eva_toggle_8h.md)


```C++
#ifndef EVATOGGLE_H
#define EVATOGGLE_H
#pragma once

#include "evaTickable.h"
#include "evaHandler.h"
#include "evaStdReaders.h"
#include "evaReaderDecors.h"

#include "evaConstants.h"

namespace eva
{
  template <class READER>
  class Toggle : public READER, public Tickable
  {
  public:
    Toggle()
    {
      enable(true);
    }

    Toggle(IHandler *listener, unsigned short eventMask)
    {
      enable(true);
      setListener(listener, eventMask);
    }

    Toggle *setListener(IHandler *listener, unsigned short eventMask)
    {
      this->listener = listener;
      this->isEnabled = (this->isEnabled & 0x0f) | (eventMask >> 8);
      return this;
    }

    Toggle *enable(bool enabled)
    {
      this->isEnabled = enabled;
      return this;
    }

    signed short getValue()
    {
      return this->levelCode;
    }

  protected:
    void tick() override
    {
      if (this->isEnabled)
        return;

      unsigned char wasLevelCode = this->levelCode;
      this->levelCode = READER::getValue();

      if ((wasLevelCode > 0) and (wasLevelCode != this->levelCode)) // any_pos -> 0
        this->notify(ON_RELEASE | wasLevelCode);

      if ((wasLevelCode != this->levelCode) and (this->levelCode > 0)) // 0 -> any_pos
        this->notify(ON_PRESS | this->levelCode);
    }
    void notify(unsigned short eventTypeMask)
    {
      if (this->listener)
        if (this->encodedState & (eventTypeMask >> 8))
          this->listener->invoke(this, (unsigned long)eventTypeMask);
    }

  protected:
    bool isEnabled = true;
    unsigned char levelCode = 0;
    IHandler *listener = nullptr;
  };

  template <int PIN, int PIN_MODE, int ACTIVE_LEVEL>
  using PinSwitch = Toggle<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVE_LEVEL>>;

  template <int PIN>
  using PullupSwitch = PinSwitch<PIN, INPUT_PULLUP, LOW>; // кнопка на GND

  template <int PIN>
  using PulldownSwitch = PinSwitch<PIN, INPUT, HIGH>; // кнопка на VCC

  template <int PIN, int THRESHOLD>
  using ThresholdSwitch = Toggle<BinarizeDecor<AnalogPinReader<PIN, INPUT>, THRESHOLD>>;

};

#endif
```


