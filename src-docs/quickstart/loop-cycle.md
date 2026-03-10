# Working with `loop()` and Tickable Objects

The EVA concept is built around a simple principle: periodic updates of all active components. Instead of writing complex state-checking code in your loop() function, you create components that update themselves and simply call the global eva::tac() function.

## Basic Principle

Your `loop()` function should be as simple as this:

```cpp
#include <evaTac.h>

void setup() {
}

void loop() {
  eva::tac(); // updates all components
}
```

Everything else — timers, button polling, LED blinking, user defined components — is handled automatic.

---

## Example 1: Component with Internal Timer

Here's a clean, minimal example where an `App` contains a component with a `RepeatTimer`. The timer is configured directly in the constructor and calls `onHeartBeat`:

```cpp
#include <evaRepeatTimer.h>
#include <evaHandler.h>
#include <evaTac.h>

using namespace eva;

class App {
private:
  RepeatTimer timer;

  void onHeartBeat(void* sender, CallbackInfo cbInfo) {
    Serial.println("Heartbeat!");
  }

public:
  App()
    : timer(1000, new Handler<App>(this, &App::onHeartBeat)) {
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  tac();
}
```

**What's happening:**

- `timer` is created with a 1000ms period

- `new Handler<App>(this, &App::onHeartBeat)` creates a handler that calls `onHeartBeat` when the timer fires

---

## Example 2: Direct Loop Access via Tickable

Sometimes you need more precise control over timing or want to check conditions on every loop iteration. For these cases, you can create components that inherit from `Tickable`. Each `Tickable` object receives its own slice of `loop()` time through its `tick()` method.
Here's an example that blinks an LED by inheriting `Tickable`:

```cpp
#include <evaTac.h>
#include <evaTickable.h>

using namespace eva;

class Blinker : public Tickable {
private:
  int pin;
  unsigned long lastChange;
  bool state;
  
  // tick() is called on every loop() iteration
  void tick() override {
    if (millis() - lastChange > 500) {
      lastChange = millis();
      state = !state;
      digitalWrite(pin, state);
    }
    return 0;
  }
  
public:
  Blinker(int ledPin) : pin(ledPin), lastChange(0), state(LOW) {
    pinMode(pin, OUTPUT);
  }
};


void setup() {
  static Blinker led(13); // Blinks LED on pin 13
}

void loop() {
  eva::tac(); // Calls tick() on Blinker and all other Tickable objects
}
```

**What's happening:**

- `Blinker` inherits from `Tickable` — this automatically adds it to the update chain

- The `tick()` method is called on **every** `loop()` iteration

- Inside `tick()`, we check if 500ms have passed and toggle the LED if needed

- `eva::tac()` walks through all registered `Tickable` objects and calls their `tick()` methods

You can add multiple `Tickable` objects, and they'll all get their time:

```cpp
Blinker led1(13);  // Blinks every 500ms
Blinker led2(12);  // Also blinks every 500ms (independent!)
Blinker led3(11);  // And another one

// All three LEDs blink independently, each with their own timing
```

Both patterns just need `eva::tac()` in your `loop()`. The library handles the rest, letting you focus on your application logic rather than wiring management.
