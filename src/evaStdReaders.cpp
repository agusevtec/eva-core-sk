#include <evaStdReaders.h>
using namespace eva;

AnalogMutablePinReader::AnalogMutablePinReader(uint8_t aPin, uint8_t aMode)
    : mPin(aPin)
{
    pinMode(aPin, aMode);
}

signed short AnalogMutablePinReader::getValue()
{
    return analogRead(mPin);
}
bool AnalogMutablePinReader::isValid()
{
    return true;
}

DigitalMutablePinReader::DigitalMutablePinReader(uint8_t aPin, uint8_t aMode)
    : mPin(aPin)
{
    pinMode(aPin, aMode);
}

signed short DigitalMutablePinReader::getValue()
{
    return digitalRead(mPin);
}

bool DigitalMutablePinReader::isValid()
{
    return true;
}
