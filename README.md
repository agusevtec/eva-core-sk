# eva-core-sk

**Event-driven architecture for Arduino**

EVA is not just a library it's a concept. Instead of fighting with `loop()` and filling it with ever-growing state-checking code, you build your application from components that know how to update themselves. One call to `eva::tac()` drives everything.

## Quick Example

```cpp
#include <evaTac.h>
#include <evaButton.h>
#include <evaHandler.h>

using namespace eva;

class App {
  void onButtonClick(void*, CallbackInfo cbInfo) {
    Serial.println("Button clicked!");
  }

  PinButton<2, INPUT_PULLUP, LOW> button = {new Handler<App>(this, &App::onButtonClick), ON_SHORTCLICK};
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

### Survival Kit (SK)
- **Buttons**: `Button`, `MultiButton`, `PinButton`, `PinMultiButton`
- **Switches**: `Toggle`, `PinSwitch`, `PullupSwitch`, `PulldownSwitch`
- **Timers**: `DelayTimer`, `RepeatTimer`
- **Indicators**: `Indicator`, `BlinkingIndicator`, `CountdownIndicator`
- **Analog Inputs**: `Joystick`, `Slider`
- **Utilities**: `List`

### Reader Decorators
- `StabilizeDecor` debouncing with 120ms stabilization
- `BinarizeDecor` convert to 0/1 based on level
- `PolarizeDecor` normalize to -1, 0, 1
- `QuantizeDecor` map analog values to discrete levels

## Why EVA?

- **Clean architecture** components know how to update themselves
- **No polling** events instead of flags in `loop()`
- **Predictable initialization** everything runs from `setup()`
- **Refactor-friendly** initialization order follows automatically
- **Zero-cost abstractions** templates resolve at compile time
- **Minimal overhead** virtual methods only at component boundaries

## 📚 Documentation

Full documentation is available at **[https://agusevtec.github.io/eva-core-sk](https://agusevtec.github.io/eva-core-sk)**

- [Quick Start: loop() and Tickable](https://agusevtec.github.io/eva-core-sk/quickstart/loop-tickable)
- [Working with Buttons](https://agusevtec.github.io/eva-core-sk/quickstart/working-with-buttons)
- [Flexibility: Beyond Standard Inputs](https://agusevtec.github.io/eva-core-sk/advanced/flexibility)
- [Optimization: Performance Without Compromise](https://agusevtec.github.io/eva-core-sk/advanced/optimization)

## Ecosystem

EVA is growing. Future modules include:
- `boxy` GUI / windowing library
- `frequencymeter` frequency measurement
- `serial` serial port handling

**Want to make your library part of the ecosystem?** [Read the invitation](https://agusevtec.github.io/eva-core-sk/ecosystem/invitation)

## Installation

### Using Arduino Library Manager
1. Open Arduino IDE
2. Go to **Sketch� Include Library� Manage Libraries**
3. Search for **"eva-core-sk"**
4. Click **Install**

## License

This library is published under MIT licence.

