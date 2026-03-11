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

## Component with Internal Timer

Here's a clean, minimal example where an application contains a component `MyAppScheduler` with a `RepeatTimer`. The timer is configured directly in the constructor and calls `onHeartBeat`:

```cpp
#include <evaRepeatTimer.h>
#include <evaHandler.h>
#include <evaTac.h>

using namespace eva;

class MyAppScheduler {
private:
  RepeatTimer timer;

  void onHeartBeat(void* sender, CallbackInfo cbInfo) {
    Serial.println("Heartbeat!");
  }

public:
  MyAppScheduler()
    : timer(1000, new Handler<MyAppScheduler>(this, &MyAppScheduler::onHeartBeat)) {
  }
};

void setup() {
  Serial.begin(9600);
  static MyAppScheduler component;
}

void loop() {
  tac();
}
```

**What's happening**

- `timer` is created with a 1000ms period

- `new Handler<MyAppScheduler>(this, &MyAppScheduler::onHeartBeat)` creates a handler that calls `onHeartBeat` when the timer fires

The library handles the rest, letting you focus on your application logic rather than wiring management.

##What's Inside Components?
To understand how EVA components work, let's peek inside one of them—RepeatTimer. It's a example of how the library builds useful functionality on top of Tickable.

Here's how a hypothetical RepeatTimer (minimal version) could look under the hood, stripped to its essence:

```cpp
#include <evaTickable.h>
#include <evaHandler.h>

using namespace eva;

class MiniRepeatTimer : public Tickable {
private:
  unsigned long interval;
  unsigned long lastFire = millis();
  IHandler* listener = nullptr;
  
  void tick() override {
    auto now = millis();
    if (now - lastFire >= interval) {
      lastFire = now;
      if (listener) listener->invoke(this, 0);
    }
  }
  
public:
  MiniRepeatTimer(unsigned period, IHandler* handler) 
    : interval(period), listener(handler) {}
};
```

**How It Works**

Tickable	gives the timer a slot in every loop() cycle


This approach is absolutely legal for the user code too — and often necessary — when you need:

* Precise control over timing

* Continuous monitoring of external events

Each Tickable object receives its own slice of loop() time through its tick() method. The library simply orchestrates the sharing.
