/**
 * eva Library - DelayTimer Example
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
  PullUpButton<3> button{new Handler<App>(this, &App::onButtonPress), ON_PRESS};
  Indicator led{13};
  DelayTimer ledOnTimer{new Handler<App>(this, &App::onLedOnTimer)};
  DelayTimer ledOffTimer{new Handler<App>(this, &App::onLedOffTimer)};

public:
  App()
  {
    Serial.println("DelayTimer Demo: Press button, LED turns on after 2s");
  }

  void onButtonPress(void *, CallbackInfo)
  {
    Serial.println("Button pressed - starting 2s timer");
    ledOnTimer.start(2000);
  }

  void onLedOnTimer(void *, CallbackInfo)
  {
    Serial.println("Timer expired - LED ON");
    led.on();
    ledOffTimer.start(1000);
  }

  void onLedOffTimer(void *, CallbackInfo)
  {
    Serial.println("LED OFF");
    led.off();
  }
};

void setup()
{
  Serial.begin(9600);
  static App app;
}

void loop()
{
  eva::tac();
}