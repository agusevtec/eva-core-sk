# Flexibility: Beyond Standard Inputs

The true power of the EVA concept and the SK part of the eva-core-sk library lies in its flexibility. Because Button and MultiButton are built on templates and decorators, they can work with any source of numerical data—not just physical pins. This section shows how you can adapt the library to unconventional input sources.

## Example 1: Differential Joystick with Custom Zone Detection

Some precision joysticks use differential readings to cancel noise and improve accuracy. Here's how to combine a differential reader with custom zone mapping to create a 3-position virtual switch:

```cpp
#include <evaMultiButton.h>
#include <evaTac.h>
#include <evaHandler.h>

using namespace eva;

// Step 1: Create a differential reader (A0 - A1)
template <int IN1, int IN2>
class DifferentialReader
{
public:
  signed short getValue()
  {
    return analogRead(IN1) - analogRead(IN2);
  }
};

// Step 2: Map raw differences to meaningful codes
template <class READER>
class ZoneMapper : public READER
{
public:
  signed short getValue()
  {
    signed short diff = READER::getValue();
    
    if (diff < -100)
      return 1;  // Left zone
    if (diff < 100)
      return 0;  // Center zone (nothing happening)
    return 2;    // Right zone
  }
};

// Step 3: Assemble into a MultiButton
using DifferentialSwitch = MultiButton<
  StabilizeDecor<
    ZoneMapper<
      DifferentialReader<A0, A1>
    >
  >
>;

class App {
private:
  DifferentialSwitch joystickZone;
  
  void onZoneEvent(void* sender, long events) {
    unsigned short zone = events & 0xFF;  // 1 or 2
    
    if (events & MB_EVENTS::ON_ACTIVE) {
      Serial.print("Entered zone ");
      Serial.println(zone);
    }
    
    if (events & MB_EVENTS::ON_INACTIVE) {
      Serial.println("Returned to center");
    }
  }
  
public:
  App() {
    joystickZone.setListener(
      new Handler<App>(this, &App::onZoneEvent),
      MB_EVENTS::ON_ACTIVE | MB_EVENTS::ON_INACTIVE
    );
  }
};
```

**What's happening:**

- `DifferentialReader` reads the difference between two analog pins, canceling common-mode noise

- `ZoneMapper` translates the continuous difference into three discrete states: left (1), center (0), right (2)

- `MultiButton` provides press/release semantics for zone entry/exit

## Example 2: Virtual Button from External Events

The same pattern works when values come from outside the normal polling loop—like interrupts, callbacks, or message decoders:

```cpp
// A reader that stores the last known state
class ExternalStateReader {
private:
  static signed short lastValue;
  
public:
  // Called from interrupt or callback
  static void update(signed short value) {
    lastValue = value;
  }
  
  signed short getValue() {
    return lastValue;
  }
};

signed short ExternalStateReader::lastValue = 0;

// Use it with standard Button
using VirtualButton = Button<StabilizeDecor<ExternalStateReader>>;

// Now any external code can inject button events:
// ExternalStateReader::update(1);  // Press
// ExternalStateReader::update(0);  // Release
```

**What's happening** 

The `Button` class then handles all timing and generates appropriate press/release/click events automatically.

## The Big Picture

The library doesn't care where the values come from. Whether it's: physical pins through standard readers, differential calculations like the joystick example, external signals injected by callbacks, any other source that can provide numerical codes

