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
   * @brief Button behavior in an Event-Driven manner
   * This implementation is based on an abstract source (@see IReader). However, for the most commonly used case
   * (the pin button), a factory method is also provided. See the example below.
   * @code {.cpp}
   * #include <evaButton.h>
   * #include <evaTac.h>
   * using namespace eva;
   * class MyApp1
   * {
   * public:
   * void onMyButton1(void *msgSender, long argsMask)
   *   {
   *     if ((Button *)msgSender == &this->myButton1)
   *       if (argsMask & Button::ONRELEASED) {}
   *   }
   * private:
   *   Button &myButton1 = Button::Create<3, INPUT_PULLUP, LOW>()
   *                         .setListener(new Handler<MyApp1>(this, &onMyButton1), Button::ON_SHORTCLICK | Button::ON_LONGCLICK);
   * } myapp1;
   * void tick()
   * {
   *   Ticker::tac();
   * }
   * @endcode
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

      this->encodedState = (this->encodedState & 0xfc) | ((this->encodedState << 1) & 0x03);
      this->encodedState = (this->encodedState & 0xfe) | (READER::getValue());

      if (this->pressTime and (millis() - this->pressTime) > 750)
      {
        notify(B_EVENTS::ON_LONGCLICK);
        this->pressTime = 0;
      }

      if ((this->encodedState & 0x3) == 0x02) // 1 -> 0
      {
        if (this->pressTime and (millis() - this->pressTime < 750))
          notify(B_EVENTS::ON_SHORTCLICK);
        notify(B_EVENTS::ON_RELEASE);
        this->pressTime = 0;
      }

      if ((this->encodedState & 0x3) == 0x01) // 0 -> 1
      {
        this->pressTime = millis();
        notify(B_EVENTS::ON_PRESS);
      }
      return 0;
    }

  protected:
    unsigned long pressTime;

  private:
    static const unsigned char ISPRESSED = 0x01;
    static const unsigned char WASPRESSED = 0x02;
    static const unsigned char ENABLED = 0x04;
  };

  /**
   * @brief factory method for the pin button case
   *
   * @tparam PIN
   * @tparam PINMODE
   * @tparam ACTIVATESON - the level of a signal corresponding to the pressed state (LOW OR HIGH)
   * @return Button&
   */
  template <int PIN, int PINMODE, int ACTIVATESON>
  using PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PINMODE>>, ACTIVATESON>>;
};

#endif
