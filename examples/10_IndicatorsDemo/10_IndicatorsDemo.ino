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

#include <eva.h>

class App : public IHandler {
private:
  // Three different indicators
  Indicator basicLed{13};              // Simple on/off
  BlinkingIndicator blinkingLed{10};   // Continuous blinking
  CountdownIndicator countdownLed{11}; // Blinks N times then stops
  
  PullUpButton<3> modeButton;          // Cycle through modes
  unsigned char mode = 0;

public:
  App() {
    modeButton.setListener(this, ON_PRESS);
    
    // Configure indicators
    blinkingLed.on(500, 50);        // 500ms period, 50% duty cycle
    countdownLed.setListener(this);  // Get notified when countdown completes
    
    Serial.println("Indicators Demo");
    Serial.println("Mode 0: All off");
    Serial.println("Mode 1: Basic on");
    Serial.println("Mode 2: Continuous blink");
    Serial.println("Mode 3: Countdown (5 blinks)");
  }
  
  void invoke(void* sender, CallbackInfo info) override {
    if (sender == &modeButton) {
      // Cycle to next mode
      mode = (mode + 1) % 4;
      
      // Turn everything off first
      basicLed.off();
      blinkingLed.off();
      countdownLed.off();
      
      // Activate new mode
      switch(mode) {
        case 1: basicLed.on(); Serial.println("Mode 1: Basic ON"); break;
        case 2: blinkingLed.startCycle(); Serial.println("Mode 2: Blinking"); break;
        case 3: countdownLed.on(200, 50, 5, this); Serial.println("Mode 3: Countdown (5 blinks)"); break;
        default: Serial.println("Mode 0: All OFF"); break;
      }
    }
    else if (sender == &countdownLed) {
      // Countdown complete notification
      Serial.println("Countdown complete!");
    }
  }
};


void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
