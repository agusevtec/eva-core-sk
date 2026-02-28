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

  /**
   * @brief Toggle - легковесная версия Button без детекции кликов
   *
   * Отличается от Button:
   * - Не хранит pressTime (экономия 4 байта!)
   * - Только события ON_ACTIVE/ON_INACTIVE
   * - Меньше кода в tick()
   * - Быстрее работает
   *
   * Идеально для:
   * - Тумблеров
   * - Концевых выключателей
   * - Герконов
   * - Датчиков движения
   */
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

    /**
     * @brief Sets the Listener for switch events
     * @param listener - callback method
     * @param eventMask - SW_EVENTS::ON_ACTIVE, ON_INACTIVE, ON_CHANGE
     */
    Toggle *setListener(IHandler *listener, unsigned short eventMask)
    {
      this->listener = listener;
      this->encodedState = (this->encodedState & 0x0f) | (eventMask >> 8);
      return this;
    }

    /**
     * @brief Enables or disables the toggle
     * @param enabled True to enable, false to disable
     * @return Pointer to this
     */
    Toggle *enable(bool enabled)
    {
      this->encodedState = (enabled) ? this->encodedState | ENABLED : this->encodedState & ~ENABLED;
      return this;
    }

    /**
     * @brief Current state of the switch
     * @return 1 - active (closed), 0 - inactive (open)
     */
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

  /**
   * @brief Pin-based switch with specified active level
   * @tparam PIN Arduino pin number
   * @tparam PIN_MODE Pin mode (INPUT_PULLUP, INPUT, etc.)
   * @tparam ACTIVE_LEVEL Level that means active (LOW or HIGH)
   */
  template <int PIN, int PIN_MODE, int ACTIVE_LEVEL>
  using PinSwitch = Toggle<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVE_LEVEL>>;

  /**
   * @brief Pull-up switch (button connected to GND)
   * @tparam PIN Arduino pin number with INPUT_PULLUP
   */
  template <int PIN>
  using PullupSwitch = PinSwitch<PIN, INPUT_PULLUP, LOW>; // кнопка на GND

  /**
   * @brief Pull-down switch (button connected to VCC)
   * @tparam PIN Arduino pin number with INPUT
   */
  template <int PIN>
  using PulldownSwitch = PinSwitch<PIN, INPUT, HIGH>; // кнопка на VCC

  /**
   * @brief Threshold-based switch using analog input
   * @tparam PIN Arduino analog pin number
   * @tparam THRESHOLD Value that separates active/inactive states
   */
  template <int PIN, int THRESHOLD>
  using ThresholdSwitch = Toggle<BinarizeDecor<AnalogPinReader<PIN, INPUT>, THRESHOLD>>;

};

#endif
