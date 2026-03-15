/**
 * eva Library - DelayTimer Example
 * 
 * Simple one-shot timer demonstration:
 * - Button press starts a 2-second timer
 * - When timer expires, LED turns on
 * - Another timer turns LED off after 1 second
 */

#include <evaTac.h>
#include <evaRepeatTimer.h>
#include <evaDelayTimer.h>
#include <evaButton.h>
#include <evaIndicator.h>


using namespace eva;


class App : public IHandler {
private:
  PullUpButton<2> button;      // Button on pin 2
  Indicator led{13};            // Built-in LED
  DelayTimer timer;             // One-shot timer
  DelayTimer offTimer;          // Timer to turn LED off

public:
  App() {
    button.setListener(this, ON_PRESS);
    Serial.println("DelayTimer Demo: Press button, LED turns on after 2s");
  }
  
  void invoke(void* sender, CallbackInfo info) override {
    if (sender == &button) {
      Serial.println("Button pressed - starting 2s timer");
      timer.start(2000, this);  // Start timer, notify us when done
    }
    else if (sender == &timer) {
      Serial.println("Timer expired - LED ON");
      led.on();
      offTimer.start(1000, this);  // Turn off after 1 second
    }
    else if (sender == &offTimer) {
      Serial.println("LED OFF");
      led.off();
    }
  }
};

App app;

void setup() {
  Serial.begin(9600);
}

void loop() {
  eva::tac();
}
