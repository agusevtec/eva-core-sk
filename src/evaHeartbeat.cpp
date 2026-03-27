#include "evaHeartbeat.h"
#include <Arduino.h>

using namespace eva;

Heartbeat::Heartbeat(unsigned long periodMs)
    : periodMs(periodMs)
    , lastBeatMs(millis())
{
}

void Heartbeat::tick()
{
    unsigned long now = millis();
    if (now - this->lastBeatMs >= this->periodMs)
    {
        this->lastBeatMs = now;
        onHeartbeat();
    }
}

unsigned long Heartbeat::getPeriod() const
{
    return this->periodMs;
}

