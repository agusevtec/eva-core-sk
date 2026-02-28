# Optimization: Separating Myth from Reality

There is a common myth in the embedded world: object-oriented programming consumes too much memory. Like many myths, this one contains a grain of truth — but only if you use OOP the wrong way.

## The Memory Myth

Virtual functions add overhead. Each virtual table costs RAM. Each virtual call costs time. But OOP does not require virtual functions.

```cpp
// Typical approach with virtual table
class IReader {
  virtual int getValue() = 0;  // +4-8 bytes per instance
};

// eva-core approach — no virtual tables
template <class READER>
class Switch : public READER, public Tickable {
  // everything resolved at compile time
};
```

Templates give polymorphic behavior without runtime cost.

## Three Levels of Event Handling

### Level 1: Handler (flexible, minimal overhead)
```cpp
btn.setListener(new Handler<App>(this, &App::onPress), mask);
```
Stores two pointers: object + method. On AVR: 4 bytes total.

### Level 2: Direct IHandler implementation
```cpp
class DirectHandler : public IHandler {
  void invoke(void* sender, long args) override {
    // handle directly
  }
};
```
No wrapper overhead, but still pays for virtual table if IHandler is virtual.

### Level 3: Tickable-only (zero event overhead)
```cpp
class SelfContained : public Tickable {
  short loop() override {
    if (condition()) react();
    return 0;
  }
};
```
No handlers, no delegates, no virtual tables.

## Choose the Right Tool

**Timers:**
- `DelayTimer` — one-shot (6 bytes)
- `IntervalTimer` — periodic (+2 bytes = 8 bytes)

**Indicators:**
- `Indicator` — basic on/off (~14 bytes)
- `Blinker` — infinite blinking (+4 bytes)
- `CountdownBlinker` — finite + callback (+1 byte)

**Buttons:**
- `Switch` — state only (3 bytes)
- `Button` — click detection (+4 bytes = 7 bytes)
- `MultiButton` — key codes (+1 byte = 8 bytes)

## The Rule

Use the simplest class that does what you need. Do not pay for features you do not use. That is real optimization.

OOP is not the problem. Virtual functions are. Templates give you clean abstraction with zero runtime cost.