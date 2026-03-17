/**
 * eva Library - Indicators Demo
 *
 * Demonstrates all indicator types:
 * - Basic Indicator (simple on/off)
 * - BlinkingIndicator (continuous blinking)
 * - CountdownIndicator (blink N times then notify)
 *
 * Hardware: LEDs on pins 9, 10, 11
 * Button on pin 2 cycles through modes
 */

#include <evaTac.h>
#include <evaButton.h>
#include <evaIndicator.h>
#include <evaBlinkingIndicator.h>
#include <evaCountdownIndicator.h>

using namespace eva;

class App
{
private:
  Indicator basicLed{9, HIGH};
  BlinkingIndicator blinkingLed{10, HIGH};
  CountdownIndicator countdownLed{11, HIGH};

  PullUpButton<3> modeButton{new Handler<App>(this, &App::onModePress), ON_PRESS};
  unsigned char mode = 0;

public:
  App()
  {
    countdownLed.setListener(new Handler<App>(this, &App::onCountdownComplete));
    Serial.println("Indicators Demo");
    Serial.println("Mode 0: All off");
    Serial.println("Mode 1: Basic on");
    Serial.println("Mode 2: Continuous blink");
    Serial.println("Mode 3: Countdown (5 blinks)");
  }

  void onModePress(void *, CallbackInfo)
  {
    mode = (mode + 1) % 4;
    Serial.print("Mode: ");
    Serial.println(mode);

    basicLed.off();
    blinkingLed.off();
    countdownLed.off();

    switch (mode)
    {
    case 1:
      basicLed.on();
      Serial.println("Mode 1: Basic ON");
      break;
    case 2:
      blinkingLed.on(2000, 50);
      Serial.println("Mode 2: Blinking");
      break;
    case 3:
      countdownLed.on(1000, 50, 5);
      Serial.println("Mode 3: Countdown (5 blinks)");
      break;
    default:
      Serial.println("Mode 0: All OFF");
      break;
    }
  }

  void onCountdownComplete(void *, CallbackInfo)
  {
    Serial.println("Countdown complete!");
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