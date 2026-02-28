

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

namespace eva
{
  struct SW_EVENTS
  {
    static const unsigned short ON_ACTIVE = 0x1000;
    static const unsigned short ON_INACTIVE = 0x2000;
    static const unsigned short ON_CHANGE = 0x3000;
  };

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
      this->encodedState = (this->encodedState & 0x0f) | (eventMask >> 8);
      return this;
    }

    Toggle *enable(bool enabled)
    {
      this->encodedState = (enabled) ? this->encodedState | ENABLED : this->encodedState & ~ENABLED;
      return this;
    }

    signed short getValue()
    {
      return this->encodedState & ISACTIVE;
    }

  protected:
    short tick() override
    {
      if (!(this->encodedState & ENABLED))
        return 0;

      unsigned char wasActive = this->encodedState & ISACTIVE;
      unsigned char isActive = READER::getValue();

      if (isActive != wasActive)
      {
        this->encodedState = (this->encodedState & ~ISACTIVE) | isActive;
        notify(isActive ? SW_EVENTS::ON_ACTIVE : SW_EVENTS::ON_INACTIVE);
      }
      return 0;
    }

    void notify(unsigned short eventTypeMask)
    {
      if (this->listener)
        if (this->encodedState & (eventTypeMask >> 8))
          this->listener->invoke(this, (unsigned long)eventTypeMask);
    }

  protected:
    unsigned char encodedState = 0; // биты: 0-ISACTIVE, 1-3 свободны, 4-7 маска событий
    IHandler *listener = nullptr;

  private:
    static const unsigned char ISACTIVE = 0x01;
    static const unsigned char ENABLED = 0x04;
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


