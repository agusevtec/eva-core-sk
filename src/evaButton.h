#ifndef EVABUTTON_H
#define EVABUTTON_H
#pragma once

#include "evaToggle.h"

namespace eva
{
  struct B_EVENTS
  {
    static const unsigned short ON_PRESS = 0x1000;
    static const unsigned short ON_RELEASE = 0x2000;
    static const unsigned short ON_SHORTCLICK = 0x4000;
    static const unsigned short ON_LONGCLICK = 0x8000;
  };

  /**
   * @brief Button with press, release, short click and long click detection
   *
   * @tparam READER Input reader type that provides getValue()
   *
   */

  template <class READER>
  class Button : public Toggle<READER>
  {
  public:
    using Toggle<READER>::Toggle;

  private:
    short tick() override
    {
      if (!(this->encodedState & ENABLED))
        return 0;

      unsigned char wasPressed = this->encodedState & ISPRESSED;
      unsigned char isPressed = READER::getValue();

      if (this->pressTime and (millis() - this->pressTime) > 750)
      {
        notify(B_EVENTS::ON_LONGCLICK);
        this->pressTime = 0;
      }

      if (wasPressed && !isPressed)
      {
        this->encodedState = this->encodedState & ~ISPRESSED;
        if (this->pressTime and (millis() - this->pressTime < 750))
          notify(B_EVENTS::ON_SHORTCLICK);
        notify(B_EVENTS::ON_RELEASE);
        this->pressTime = 0;
      }

      if (!wasPressed && isPressed)
      {
        this->encodedState = this->encodedState | ISPRESSED;
        this->pressTime = millis();
        notify(B_EVENTS::ON_PRESS);
      }
      return 0;
    }

  protected:
    unsigned long pressTime;

  private:
    static const unsigned char ISPRESSED = 0x01;
    static const unsigned char ENABLED = 0x04;
  };

  /**
   * @brief Button connected directly to a digital pin
   * Includes stabilization and binarization decorators.
   * Debounces input and generates events based on button state changes.
   * Long click threshold is fixed at 750ms.
   *
   * @tparam PIN
   * @tparam PIN_MODE
   * @tparam ACTIVATES_ON - the level of a signal corresponding to the pressed state (LOW OR HIGH)
   * @return Button&
   */
  template <int PIN, int PIN_MODE, int ACTIVATES_ON>
  using PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;
};

#endif
