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

## Example: Component with Internal Timer

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

The library handles the rest, letting you focus on your application logic rather than wiring management.
