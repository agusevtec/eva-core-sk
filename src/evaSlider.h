#ifndef EVASLIDER_H_
#define EVASLIDER_H

#include "evaStdReaders.h"
#include <Arduino.h>

namespace eva
{
  /**
   * @brief Maps analog readings to 0-255 range
   */
  template <class READER, int MIN, int MAX>
  class Slider : public READER
  {
  public:
    /**
     * @brief Gets normalized slider position
     * @return Value from 0 to 255
     */
    signed short getValue()
    {
      return constrain(map(READER::getValue(), MIN, MAX, 0, 255), 0, 255);
    }
  };
  /**
   * @brief Pin-based slider mapping analog readings to 0-255 range
   * @tparam PIN Arduino pin number
   * @tparam PIN_MODE Pin mode (usually INPUT)
   * @tparam MIN Minimum analog reading
   * @tparam MAX Maximum analog reading
   */
  template <int PIN, int PIN_MODE, int MIN, int MAX>
  using PinSlider = Slider<AnalogPinReader<PIN, PIN_MODE>, MIN, MAX>;
};

#endif
