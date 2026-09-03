#pragma once

#include "evaStdReaders.h"
#include <Arduino.h>

namespace eva
{
  /**
   * @brief Maps analog readings to 1000-2000 range
   * @tparam TReader Underlying reader type
   * @tparam tMinPos Minimum analog reading
   * @tparam tMaxPos Maximum analog reading
   */
  template <class TReader, unsigned short tMinPos = 0, unsigned short tMaxPos = 1024>
  class Slider : public TReader
  {
  public:
    /**
     * @brief Constructs a Slider
     * @param args Additional arguments passed to TReader constructor
     */
    template <typename... Args>
    Slider(Args... args) : TReader(args...)
    {
    }
    /**
     * @brief Gets normalized slider position with custom range
     * @param aMinPos Minimum analog reading
     * @param aMaxPos Maximum analog reading
     * @return Value from 1000 to 2000
     */
    signed short getValue(unsigned short aMinPos, unsigned short aMaxPos)
    {
      return constrain(map(TReader::getValue(), aMinPos, aMaxPos, 1000, 2000), 1000, 2000);
    }
    /**
     * @brief Gets normalized slider position
     * @return Value from 1000 to 2000
     */
    signed short getValue()
    {
      return getValue(tMinPos, tMaxPos);
    }
  };
  /**
   * @brief Pin-based slider mapping analog readings to 0-255 range
   * @tparam tPin Arduino pin number
   * @tparam tPinMode Pin mode (usually INPUT)
   * @tparam tMinPos Minimum analog reading
   * @tparam tMaxPos Maximum analog reading
   */
  template <unsigned short tPin, int tPinMode, unsigned short tMinPos, unsigned short tMaxPos>
  using PinSlider = Slider<AnalogPinReader<tPin, tPinMode>, tMinPos, tMaxPos>;
};
