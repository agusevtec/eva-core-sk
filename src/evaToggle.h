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
  /**
   * @brief Toggle - легковесная версия Button без детекции кликов
   *
   * Отличается от Button:
   * - Не хранит pressTime (экономия 4 байта!)

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
     * @param eventMask - ON_ACTIVE, ON_INACTIVE, ON_CHANGE
     */
    Toggle *setListener(IHandler *listener, unsigned short eventMask)
    {
      this->listener = listener;
      this->curiosity = eventMask;
      return this;
    }

    /**
     * @brief Enables or disables the toggle
     * @param enabled True to enable, false to disable
     * @return Pointer to this
     */
    Toggle *enable(bool enabled)
    {
      if (this->levelCode < 0 && enabled)
        this->levelCode = 0;
      if (this->levelCode >= 0 && !enabled)
        this->levelCode = -1;
      return this;
    }

    /**
     * @brief Gets the button level code identifying which button was pressed
     * @return Level code (0 for no button, >0 for specific button)
     */
    signed short getValue()
    {
      if (this->levelCode > 0)
        return this->levelCode;
      return 0;
    }

  protected:
    void tick() override
    {
      if (this->levelCode < 0)
        return;

      unsigned char wasLevelCode = this->levelCode;
      this->levelCode = READER::getValue();
      if ((wasLevelCode > 0) and (wasLevelCode != this->levelCode)) // any_pos -> 0
        this->notify(ON_RELEASE, wasLevelCode);

      if ((wasLevelCode != this->levelCode) and (this->levelCode > 0)) // 0 -> any_pos
        this->notify(ON_PRESS, this->levelCode);
    }

    void notify(unsigned short eventType, unsigned short eventCode)
    {
      if (this->listener)
        if (this->curiosity & eventType)
          this->listener->invoke(this, eventType, eventCode);
    }

  protected:
    unsigned char curiosity = 0;
    signed char levelCode = 0;
    IHandler *listener = nullptr;
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
