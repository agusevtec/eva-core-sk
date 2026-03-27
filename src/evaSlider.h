#ifndef EVASLIDER_H_
#define EVASLIDER_H

#include "evaStdReaders.h"
#include <Arduino.h>

namespace eva
{
  /**
   * @brief Maps analog readings to 1000-2000 range
   */
  template <class READER, unsigned short MIN_POS, unsigned short MAX_POS>
  class Slider : public READER
  {
  public:
    /**
     * @brief Gets normalized slider position
     * @return Value from 0 to 255
     */
    signed short getValue()
    {
      return constrain(map(READER::getValue(), MIN_POS, MAX_POS, 1000, 2000), 1000, 2000);
    }
  };
  /**
   * @brief Pin-based slider mapping analog readings to 0-255 range
   * @tparam PIN Arduino pin number
   * @tparam PIN_MODE Pin mode (usually INPUT)
   * @tparam MIN_POS Minimum analog reading
   * @tparam MAX_POS Maximum analog reading
   */
  template <unsigned short PIN, int PIN_MODE, unsigned short MIN_POS, unsigned short MAX_POS>
  using PinSlider = Slider<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, MAX_POS>;
};

#endif
