/**
 * eva Library - Custom Tickable Example
 * 
 * Create a custom class that needs periodic updates:
 * - RampGenerator produces sawtooth wave (0-255)
 * - Updates 50 times per second via tick()
 * - Display value every 2 seconds
 */

#include <evaTac.h>
#include <evaTickable.h>
#include <evaRepeatTimer.h>
using namespace eva;


// Custom Tickable class that generates a ramp wave
class RampGenerator : public Tickable {
private:
  unsigned char value = 0;
  unsigned long lastUpdate = 0;
  const unsigned short interval = 20; // 50Hz update rate

public:
  unsigned char getValue() { return value; }
  
protected:
  void tick() override {
    unsigned long now = millis();
    if (now - lastUpdate >= interval) {
      value++;  // Increment ramp
      lastUpdate = now;
    }
  }
};

class App : public IHandler {
private:
  RampGenerator ramp;              // Custom tickable object
  RepeatTimer reportTimer{2000, this}; // Report every 2 seconds

public:
  App() {
    Serial.println("Tickable Inheritance Demo");
    Serial.println("Ramp value updates 50x/sec via tick()");
  }
  
  void invoke(void* sender, CallbackInfo info) override {
    if (sender == &reportTimer) {
      Serial.print("Ramp value: ");
      Serial.println(ramp.getValue());
    }
  }
};

App app;

void setup() {
  Serial.begin(9600);
}

void loop() {
  eva::tac();  // This ticks ALL Tickable objects (ramp + reportTimer)
}
