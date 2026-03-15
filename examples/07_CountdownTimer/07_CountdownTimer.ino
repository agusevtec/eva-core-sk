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

class App : public IHandler {
private:
  PullUpButton<2> connectButton;    // Start connection attempt
  BlinkingIndicator led{13};                  // Status LED
  CountdownTimer retryTimer;          // Retry timer
  unsigned char attempt = 0;

public:
  App() {
    connectButton.setListener(this, ON_PRESS);
    retryTimer.setListener(this);
    Serial.println("CountdownTimer Demo: Connection Retry");
    Serial.println("Press button to start - retries 3 times");
  }
  
  void invoke(void* sender, CallbackInfo info) override {
    if (sender == &connectButton) {
      Serial.println("\nStarting connection...");
      attempt = 0;
      led.on(200, 50);  // Blink while connecting
      retryTimer.start(1000, 3, this);  // Retry 3 times, 1s apart
    }
    else if (sender == &retryTimer) {
      // info.eventArg contains remaining retries (2,1,0)
      attempt = 3 - info.eventArg;
      
      if (info.eventArg > 0) {
        Serial.print("Retry attempt ");
        Serial.print(attempt);
        Serial.println(" failed - trying again");
      } else {
        // All retries exhausted
        Serial.println("All retries failed - connection timeout");
        led.off();
      }
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
