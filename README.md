# EVA Core | EVA Survival Kit (eva-core-sk)

A library providing the architectural core with essential components for event-driven Arduino applications.

It implements—and in fact defines—a concept: Extremely Versatile Architecture (EVA). This approach is designed to make user code comfortable and intuitive. Instead of fighting with loop() and filling it with ever-growing state-checking code, you build your application from components that know how to update themselves. A single call to eva::tac() drives everything.

## Quick Example

```cpp
#include <evaTac.h>
#include <evaButton.h>
#include <evaCountdownTimer.h>

using namespace eva;

class App {
  PullUpButton<3> button{ &onButtonClickHandler, ON_SHORTCLICK };
  CountdownTimer countdownTimer{ &onTimerTickHandler };

  Handler<App> onButtonClickHandler{ this, &onButtonClick };
  void onButtonClick(void* sender, CallbackInfo cbInfo) {
    Serial.println("Button clicked!");
    if (!countdownTimer.isRunning())
      countdownTimer.start(1000, 5);
  }

  Handler<App> onTimerTickHandler{ this, &App::onTimerTick };
  void onTimerTick(void* sender, CallbackInfo cbInfo) {
    Serial.println("Countdown!");
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();  // One call drives everything
}
```

## Key Concepts

### Tickable
Everything that needs time becomes part of a single update chain. Just inherit from `Tickable` and implement `tick()`.

### Handler
Components don't poll—they notify. Bind events to methods naturally with `Handler`.

### Template Composition
Flexibility without performance loss. Everything resolves at compile time.

## What's Inside

### Core
- `Tickable` base class for all updateable objects
- `IHandler` / `Handler` / `HandlerF` event handling
- `IReader` / `IReaderAdapter` input abstraction
- `Heartbeat` base class for objects that need periodic updates at fixed intervals

### Survival Kit (SK)
- **Buttons**: `Switch`, `Button`, `ScrollButton` and its variations
- **Switches**: `PinSwitch`, `PullupSwitch`, `PulldownSwitch`
- **Timers**: `DelayTimer`, `RepeatTimer`, `CountdownTimer`
- **Indicators**: `Indicator`, `BlinkingIndicator`, `CountdownIndicator`
- **Analog Inputs**: `Joystick`, `Slider`
- **Utilities**: `List`

### Reader Decorators
- `DebounceDecor` debouncing with 120ms stabilization
- `BinarizeEqDecor`, `BinarizeGtDecor`, `BinarizeLtDecor` convert to 0/1 based on level
- `QuantizeDecor` map analog values to discrete levels

## Why EVA?

- **Clean architecture** components know how to update themselves
- **No polling** events instead of flags in `loop()`
- **Predictable initialization** everything runs from `setup()`
- **Refactor-friendly** initialization order follows automatically
- **Zero-cost abstractions** templates resolve at compile time
- **Minimal overhead** virtual methods only at component boundaries

## Documentation

Full documentation is available at **[https://agusevtec.github.io/eva-core-sk](https://agusevtec.github.io/eva-core-sk)**

- [Quick Start: loop() and Tickable](https://agusevtec.github.io/eva-core-sk/quickstart/loop-cycle)
- [Working with Buttons](https://agusevtec.github.io/eva-core-sk/quickstart/working-with-buttons)
- [Flexibility: Beyond Standard Inputs](https://agusevtec.github.io/eva-core-sk/quickstart/flexibility)
- [Optimization: Performance Without Compromise](https://agusevtec.github.io/eva-core-sk/quickstart/performance)

## Ecosystem

Currently, the following projects are part of the ecosystem:

EVA Motors – micro-motor drivers: https://github.com/agusevtec/eva-motors

EVA Boxy – declarative GUI framework: https://github.com/agusevtec/eva-boxy

**Want to make your library part of the ecosystem?** [Read the invitation](https://agusevtec.github.io/eva-core-sk/ecosystem/invitation)

## Installation

### Using Arduino Library Manager
1. Open Arduino IDE
2. Go to **Sketch -> Include Library -> Manage Libraries**
3. Search for **"eva-core-sk"**
4. Click **Install**

## License

This library is published under MIT licence.

