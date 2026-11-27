#include <evaPinReaders.h>

using namespace eva;

MutableAnalogPinReader::MutableAnalogPinReader(uint8_t aPin, uint8_t aMode)
    : mPin(aPin)
{
    pinMode(aPin, aMode);
}

signed short MutableAnalogPinReader::getValue()
{
    return analogRead(mPin);
}
bool MutableAnalogPinReader::isValid()
{
    return true;
}

MutableDigitalPinReader::MutableDigitalPinReader(uint8_t aPin, uint8_t aMode)
    : mPin(aPin)
{
    pinMode(aPin, aMode);
}

signed short MutableDigitalPinReader::getValue()
{
    return digitalRead(mPin);
}

bool MutableDigitalPinReader::isValid()
{
    return true;
}
