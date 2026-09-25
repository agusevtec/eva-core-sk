/**
 * EVA Core | EVA Survival Kit - RepeatTimer Example (Simple Scheduler)
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

class App
{
private:
  Handler<App> onButtonPressHandler{this, &App::onButtonPress};
  void onButtonPress(void *, CallbackInfo)
  {
    if (!tickTimer.isRunning())
    {
      tickTimer.start();
      Serial.println("Timer resumed");
      led.on();
    }
    else
    {
      tickTimer.stop();
      Serial.println("Timer paused");
      led.off();
    }
  }

  Handler<App> onTickTimerHandler{this, &App::onTickTimer};
  void onTickTimer(void *, CallbackInfo)
  {
    Serial.println("tick");
  }

  PullUpButton<3> button{&onButtonPressHandler, ON_PRESS};
  Indicator led{13};
  RepeatTimer tickTimer{1000, &onTickTimerHandler};

public:
  App()
  {
    Serial.println("RepeatTimer Demo: Timer ticks every second");
    Serial.println("Press button to pause/resume");
  }
};

void setup()
{
  Serial.begin(9600);
  Serial.println("=== RepeatTimer Demo ===");
  static App app;
}

void loop()
{
  eva::tac();
}