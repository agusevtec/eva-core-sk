# Performance

There's a persistent myth in the Arduino world: object-oriented programming means overhead.

Like most myths, this one contains a grain of truth—but only a grain.

The overhead in OOP comes almost exclusively from one feature: virtual methods. 

The eva-core-sk library is designed around this reality. 
Look at how buttons are built:

```cpp
template <int PIN, int PINMODE, int ACTIVATES_ON>
using PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PINMODE>>, ACTIVATES_ON>>;
```

This entire chain resolves at compile time. 

#Efficiency Through Composition

Multiple Discrete Buttons via One Reader

Sometimes you have several discrete buttons but want to handle them through `Switch` or `Button` for unified event handling. Create a custom reader that checks each pin and returns a unique code:

```cpp
#include <evaSwitch.h>
#include <evaTac.h>
#include <evaHandler.h>

using namespace eva;

class MyBankReader {
public:
  ButtonBankReader() {
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
  }
  
  signed short getValue() {
    if (digitalRead(2) == LOW) return 'u';  // Up button
    if (digitalRead(3) == LOW) return 'd';  // Down button
    if (digitalRead(4) == LOW) return 'l';  // Left button
    if (digitalRead(5) == LOW) return 'r';  // Right button
    return 0;  // No button
  }
};


class App {
private:
  Switch<StabilizeDecor<MyBankReader>> navButtons;
  
  void onButtonPress(void* sender, CallbackInfo cbInfo) {
    char button = cbInfo.eventArg;  // 'u', 'd', 'l', or 'r'
    
    Serial.print("Pressed: ");
    switch(button) {
      case 'u': Serial.println("UP"); break;
      case 'd': Serial.println("DOWN"); break;
      case 'l': Serial.println("LEFT"); break;
      case 'r': Serial.println("RIGHT"); break;
    }
  }
  
public:
  App() : navButtons() {
    navButtons.setListener(
      new Handler<App>(this, &App::onButtonPress),
      ON_PRESS  // Only care about presses
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
**What's happening**

 Pin configuration lives in the reader's constructor—hardware setup stays with the component that owns it. The reader translates physical pins into meaningful codes ('u', 'd', 'l', 'r'). Button handles all the timing—you just react to clean ON_PRESS events with the button identity already decoded.

This approach is highly memory-efficient compared to using multiple Switch objects. On memory-constrained devices like Arduino, this can make the difference between fitting your program or running out of space.

## Multiple Paths to the Same Goal

The library offers different ways to handle events, each with different trade-offs:

### 1. Handler Templates (Convenient)
```cpp
class App{
  PeriodTimer pt = {1000, new Handler<App>(this, &App::onTimer)};
  
  void onTimer(void* sender, CallbackInfo cbInfo) {
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

  void invoke(void* sender, CallbackInfo cbInfo) override {
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


### Buttons: From Lightweight to Feature-Rich

| Class | When to Use |
|-------|----------|
| `Switch` | For simple active/inactive state tracking |
| `Button` | When you need click detection (short/long press) |
| `KeyButton` | For auto-repeating keys (like keyboard keys) |


### Timers: From Lightweight to Feature-Rich

| Class | When to Use |
|-------|----------|
| `DelayTimer` | For one-shot delays and timeouts |
| `RepeatTimer` | For periodic tasks and heartbeats |
| `CountdownTimer` | For retry logic and countdown sequences |

### Indicators: From Simple to Smart

| Class | When to Use |
|-------|-------------|
| `Indicator` | For basic on/off LED control |
| `BlinkingIndicator` | When you need blinking with period/duty cycle |
| `CountdownIndicator` | For N blinks followed by notification |

Choose the right abstraction for each job, and pay only for what you actually need.
