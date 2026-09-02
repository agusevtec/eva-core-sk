#pragma once

#include "evaDelayTimer.h"
#include <Arduino.h>

namespace eva
{
  /**
   * @brief Basic indicator (LED) control
   */
  class Indicator
  {
  public:
    /**
     * @brief Constructor
     * @param pin Arduino pin number
     * @param activationLevel Level that turns indicator on (LOW, HIGH, or PWM value)
     */
    Indicator(unsigned pin, int activationLevel = HIGH);
    
    /**
     * @brief Turns the indicator on
     */
    void on();
    
    /**
     * @brief Turns the indicator off
     */
    void off();

  private:
    int pin;
    unsigned char activationLevel;
  };


}
