#pragma once

#include "evaStdReaders.h"
#include <Arduino.h>

namespace eva
{
  /**
   * @brief Maps analog readings to 0-1000 range
   * @tparam TReader Underlying reader type
   * @tparam tMinPos Minimum analog reading
   * @tparam tMaxPos Maximum analog reading
   */
  template <class TReader, signed short tMinPos = 0, signed short tMaxPos = 1024>
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
     * @return Value from 0 to 1000
     */
    signed short getValue(signed short aMinPos, signed short aMaxPos)
    {
      return constrain(map(TReader::getValue(), aMinPos, aMaxPos, 0, 1000), 0, 1000);
    }
    /**
     * @brief Gets normalized slider position
     * @return Value from 0 to 1000
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
  template <signed short tPin, int tPinMode, signed short tMinPos, signed short tMaxPos>
  using PinSlider = Slider<AnalogPinReader<tPin, tPinMode>, tMinPos, tMaxPos>;
};
