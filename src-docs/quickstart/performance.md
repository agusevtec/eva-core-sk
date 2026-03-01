# Performance

There's a persistent myth in the Arduino world: object-oriented programming means overhead.

Like most myths, this one contains a grain of truth—but only a grain.

The overhead in OOP comes almost exclusively from one feature: virtual methods. 

Each virtual method adds:

- A vtable pointer per object (2-4 bytes of RAM)

- A vtable per class (stored in flash, negligible)

- Indirect function call overhead (a few cycles)

The eva library is designed around this reality. 
Look at how buttons are built:

```cpp
template <int PIN, int PINMODE, int ACTIVATESON>
using PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PINMODE>>, ACTIVATESON>>;
```

This entire chain resolves at compile time. 

## Multiple Paths to the Same Goal

The library offers different ways to handle events, each with different trade-offs:

### 1. Handler Templates (Convenient)
```cpp
class App{
  PeriodTimer pt = {1000, new Handler<App>(this, &App::onTimer)};
  
  void onTimer(void*, long) {
    // Handle event directly
  }
};
```

- Clean, readable, refactor-friendly

- Perfect for prototypes and memory consumption careless cases

### 2. Direct IHandler Implementation (Minimal)
```cpp
class App : public IHandler {
  PeriodTimer pt = {1000, this};

  void invoke(void*, long) override {
    // Handle event directly
  }
};

```
- for the cases when RAM matters

### 3. Tickable Subclass (Tightest control)
```cpp
class App : public Tickable {
  short tick() override {
    // Called on every loop() iteration
    // Do your own timing
    return 0;
  }
};
```
- One virtual call per `loop()` iteration
- Maximum control, minimum abstraction
- Ideal for performance-critical or continuously monitored logic

## Choose the Right Tool: Hierarchies Built for Efficiency

The library provides class hierarchies that let you pick the exact level of functionality you need—no more, no less.

### Indicators: From Simple to Smart

| Class | Overhead | When to Use |
|-------|----------|-------------|
| `Indicator` | Minimal | Just turn an LED on/off |
| `BlinkingIndicator` | Small + 2 timers | Need blinking with period/duty cycle |
| `CountdownIndicator` | Same as above + counter | Need N blinks then notification |


### Buttons: From Lightweight to Feature-Rich

| Class | RAM | Features |
|-------|-----|----------|
| `Toggle` | 1 byte | Just active/inactive states |
| `Button` | +4 bytes | Adds pressTime for click detection |
| `MultiButton` | Same as Button | Multiple codes, same overhead |


### Timers: One-Shot or Repeating

| Class | Overhead | Behavior |
|-------|----------|----------|
| `DelayTimer` | Minimal | Fires once |
| `RepeatTimer` | Same + period storage | Fires repeatedly |

Choose the right abstraction for each job, and pay only for what you actually need.
