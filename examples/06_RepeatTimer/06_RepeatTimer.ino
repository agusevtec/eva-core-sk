/**
 * eva Library - RepeatTimer Example (Simple Scheduler)
 * 
 * A periodic timer that fires every second:
 * - Prints "tick" to Serial
 * - Toggles LED on/off
 * - Can be stopped/started with button
 */


#include <evaTac.h>
#include <evaRepeatTimer.h>
#include <evaButton.h>
#include <evaSlider.h>
#include <evaIndicator.h>

using namespace eva;


class App : public IHandler {
private:
  PullUpButton<2> button;       // Start/stop button
  Indicator led{13};             // Status LED
  RepeatTimer timer{1000, this}; // 1-second periodic timer
  bool running = true;

public:
  App() {
    button.setListener(this, ON_PRESS);
    Serial.println("RepeatTimer Demo: Timer ticks every second");
    Serial.println("Press button to pause/resume");
  }
  
  void invoke(void* sender, CallbackInfo info) override {
    if (sender == &button) {
      running = !running;
      if (running) {
        timer.start();  // Resume timer
        Serial.println("Timer resumed");
      } else {
        timer.stop();   // Pause timer
        Serial.println("Timer paused");
        led.off();
      }
    }
    else if (sender == &timer) {
      // Timer tick - toggle LED and print
      led.on();
      Serial.println("tick");
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
