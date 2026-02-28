#include "evaIndicator.h"
#include <Arduino.h>
using namespace eva;

Indicator::Indicator(unsigned pin, int activatesBy)
    : pin(pin),
      activationLevel(activatesBy)
{
  pinMode(this->pin, OUTPUT);
  off();
}

void Indicator::on()
{
  if (this->activationLevel == LOW)
    digitalWrite(this->pin, LOW);
  else if (this->activationLevel == HIGH)
    digitalWrite(this->pin, HIGH);
  else
    analogWrite(this->pin, this->activationLevel);
}

void Indicator::off()
{
  if (this->activationLevel == LOW)
    digitalWrite(this->pin, HIGH);
  else if (this->activationLevel == HIGH)
    digitalWrite(this->pin, LOW);
  else
    digitalWrite(this->pin, LOW);
}


