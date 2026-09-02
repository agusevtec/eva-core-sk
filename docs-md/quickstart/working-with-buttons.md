# Working with Buttons

The SK part of the eva-core-sk library provides a flexible and powerful button handling system that supports various hardware configurations and event types. Buttons are implemented as template classes, allowing you to precisely configure their behavior while maintaining optimal performance - and provides aliases for the most common use cases.

## Basic Button: `PinButton`

For most applications with a button connected directly to a digital pin, use the `PinButton` alias:

```cpp
#include <evaButton.h>
#include <evaTac.h>
#include <evaHandler.h>

using namespace eva;

class App {
private:
  // Button on pin 2, using INPUT_PULLUP, active LOW (button to GND)
  PinButton<2, INPUT_PULLUP, LOW> button;
  
  void onButtonEvent(void* sender, CallbackInfo cbInfo) {
    if (cbInfo.eventType & ON_SHORTCLICK) {
      Serial.println("Button clicked!");
    }
    if (cbInfo.eventType & ON_LONGCLICK) {
      Serial.println("Button long pressed!");
    }
  }
  
public:
  App() {
    // Set up the button handler
    button.setListener(
      new Handler<App>(this, &App::onButtonEvent),
      ON_SHORTCLICK | ON_LONGCLICK
    );
  }
};


void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac(); // Buttons need regular updates
}
```

## How `PinButton` is Built

The `PinButton` alias demonstrates the library's composable architecture:

```cpp
template <int tPin, int tPinMode, int tActivatesOn>
using PinButton = Button<BinarizeEqDecor<DebounceDecor<DigitalPinReader<tPin, PINMODE>>, tActivatesOn>>;
```

This builds the button from several layers:

| Layer | Purpose |
|-------|---------|
| `DigitalPinReader<tPin, tPinMode>` | Reads the raw digital pin value |
| `DebounceDecor<...>` | Stabilizes readings (120ms debounce) |
| `BinarizeEqDecor<..., tActivatesOn>` | Converts the reading to 0/1 based on active level |
| `Button<...>` | Adds press/release/click detection logic |


---

## PinMultiButton: Multiple Buttons on One Pin
The Button class allows you to connect several buttons to a single analog pin using a resistor ladder. Each button produces a different analog value, which the library quantizes into discrete levels.

## Hardware Setup

Connect buttons as a resistor ladder:

```
    ADC Pin  -----+--R1--+--R2--+-- ... --+--Rn--+
    (analog in)   |      |      |         |      |
                   \      \      \         \      \
                  |      |      |         |      |
      GND    -----+------+------+-- ... --+------+
```

Each button, when pressed, creates a voltage divider with a unique value.

## Software Configuration with `PinMultiButton`


```cpp
#include <evaButton.h>
#include <evaTac.h>
#include <evaHandler.h>

using namespace eva;

class App {
private:
  // Values are the expected analog readings for each button
  PinMultiButton<A0, INPUT, 
                 100,  // Button 1 threshold
                 300,  // Button 2 threshold
                 500,  // Button 3 threshold
                 700>  // Button 4 threshold
    buttonBank;
  
  void onButtonEvent(void* sender, CallbackInfo cbInfo) {
    // The button level is encoded in callback info
    unsigned char levelCode = cbInfo.eventArg;
  
    // Get the actual threshold value that defines this level
    unsigned short threshold = buttonBank.getLevel(levelCode);
  
    Serial.print("Received code: ");
    Serial.print(levelCode);
    Serial.print(" (threshold: ");
    Serial.print(threshold);
    Serial.println(")");

    if (cbInfo.eventType & ON_SHORTCLICK) {
      Serial.println("short clicked");
    }
    
    if (cbInfo.eventType & ON_LONGCLICK) {
      Serial.println("long pressed");
    }
  }
  
public:
  App() {
    buttonBank.setListener(
      new Handler<App>(this, &App::onButtonEvent),
      ON_SHORTCLICK | ON_LONGCLICK
    );
  }
};


void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
```
Event information: The handler receives a CallbackInfo structure containing both the event type (the event mask) and the button identifier (1 for first button, 2 for second, etc.)

## How `PinMultiButton` is Built

The `PinMultiButton` alias shows an even more sophisticated composition:

```cpp
template <int tPin, int PINMODE, signed short... tLevels>
using PinMultiButton = Button<QuantizeDecor<DebounceDecor<AnalogPinReader<tPin, PINMODE>>, tLevels...>>;
```

The layers:

| Layer | Purpose |
|-------|---------|
| `AnalogPinReader<tPin, PINMODE>` | Reads raw analog values |
| `DebounceDecor<...>` | Stabilizes readings (120ms debounce) |
| `QuantizeDecor<..., tLevels...>` | Maps analog values to button indices (1..n) |
| `Button<...>` | Adds button state machine and event generation |

Because the composition forms a single inheritance chain, all public methods of every layer remain accessible on the final object. This allows you to reach through the abstraction layers when needed.

For example, when a button press is detected, you can retrieve which physical button (level) triggered the event by calling getLevel() from QuantizeDecor
