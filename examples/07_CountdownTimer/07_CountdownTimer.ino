/**
 * eva Library - CountdownTimer Example (Connection Retry)
 *
 * Simulates connection retry logic:
 * - Button press attempts to "connect"
 * - Countdown timer retries 3 times with 1-second intervals
 * - Reports success/failure after retries
 */

#include <evaTac.h>
#include <evaCountdownTimer.h>
#include <evaButton.h>
#include <evaBlinkingIndicator.h>

using namespace eva;

class App
{
private:
  PullUpButton<3> connectButton{new Handler<App>(this, &App::onConnectPress), ON_PRESS};
  BlinkingIndicator led{13};
  CountdownTimer retryTimer{new Handler<App>(this, &App::onRetryTimer)};

public:
  App()
  {
    Serial.println("CountdownTimer Demo: Connection Retry");
    Serial.println("Press button to start - retries 3 times");
  }

  void onConnectPress(void *, CallbackInfo)
  {
    Serial.println("\nStarting connection...");
    led.on(200, 50);
    retryTimer.start(1000, 3);
  }

  void onRetryTimer(void *, CallbackInfo info)
  {
    // info.eventArg contains remaining retries (2,1,0)
    unsigned char attempt = 3 - info.eventArg;

    if (info.eventArg > 0)
    {
      Serial.print("Retry attempt ");
      Serial.print(attempt);
      Serial.println(" failed");
    }
    else
    {
      Serial.println("All retries failed");
      led.off();
    }
  }
};

void setup()
{
  Serial.begin(9600);
  Serial.println("===  CountdownTimer Demo ===");
  static App app;
}

void loop()
{
  eva::tac();
}