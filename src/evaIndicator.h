#ifndef EVAINDICATOR_H_
#define EVAINDICATOR_H_
#include "evaDelayTimer.h"

#include <Arduino.h>

namespace eva
{
  class Indicator
  {
  public:
    Indicator(unsigned pin, int activationLevel = HIGH);
    void on();
    void off();

  private:
    int pin;
    unsigned char activationLevel;
  };


}

#endif
