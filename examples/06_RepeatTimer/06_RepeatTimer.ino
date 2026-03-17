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
#include <evaIndicator.h>

using namespace eva;

class App {
private:
  PullUpButton<3> button{new Handler<App>(this, &App::onButtonPress), ON_PRESS};
  Indicator led{13};
  RepeatTimer tickTimer{1000, new Handler<App>(this, &App::onTickTimer)};
  bool running = true;

public:
  App() {
    Serial.println("RepeatTimer Demo: Timer ticks every second");
    Serial.println("Press button to pause/resume");
  }

  void onButtonPress(void*, CallbackInfo) {
    running = !running;
    if (running) {
      tickTimer.start();
      Serial.println("Timer resumed");
      led.on();
    } else {
      tickTimer.stop();
      Serial.println("Timer paused");
      led.off();
    }
  }

  void onTickTimer(void*, CallbackInfo) {
    Serial.println("tick");
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}