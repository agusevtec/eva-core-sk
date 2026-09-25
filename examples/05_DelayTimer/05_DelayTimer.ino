/**
 * EVA Core | EVA Survival Kit - DelayTimer Example
 *
 * Simple one-shot timer demonstration:
 * - Button press starts a 2-second timer
 * - When timer expires, LED turns on
 * - Another timer turns LED off after 1 second
 */

#include <evaTac.h>
#include <evaDelayTimer.h>
#include <evaButton.h>
#include <evaIndicator.h>

using namespace eva;

class App
{
private:
  Handler<App> onButtonPressHandler{this, &App::onButtonPress};
  void onButtonPress(void *, CallbackInfo)
  {
    Serial.println("Button pressed - starting 2s timer");
    ledOnTimer.start(2000);
  }

  Handler<App> onLedOnTimerHandler{this, &App::onLedOnTimer};
  void onLedOnTimer(void *, CallbackInfo)
  {
    Serial.println("Timer expired - LED ON");
    led.on();
    ledOffTimer.start(1000);
  }

  Handler<App> onLedOffTimerHandler{this, &App::onLedOffTimer};
  void onLedOffTimer(void *, CallbackInfo)
  {
    Serial.println("LED OFF");
    led.off();
  }

  PullUpButton<3> button{&onButtonPressHandler, ON_PRESS};

  Indicator led{13};

  DelayTimer ledOnTimer{&onLedOnTimerHandler};
  DelayTimer ledOffTimer{&onLedOffTimerHandler};

public:
  App()
  {
    Serial.println("DelayTimer Demo: Press button, LED turns on after 2s");
  }
};

void setup()
{
  Serial.begin(9600);
  Serial.println("=== DelayTimer Demo ===");
  static App app;
}

void loop()
{
  eva::tac();
}