/**
 * eva Library - Switch Initialization Variants
 */

#include <evaTac.h>
#include <evaRepeatTimer.h>
#include <evaSwitch.h>

using namespace eva;

class App {
private:
  // Power switch: track active/inactive states
  // Digital pin 2 to GND (using internal pull-up) - On/Off Switch
  // Physical switches - use ON_ACTIVE/ON_INACTIVE
  PullupSwitch<2> modeToggle{ new Handler<App>(this, &App::onPowerSwitchActive), ON_CHANGE };

  // Reset button: press and release events
  // The class is a  same but semantic is differ: use aliases ON_RELEASE
  // Switch 2: Digital pin 3 to GND (using internal pull-up) - Momentary Button
  PinSwitch<3, INPUT_PULLUP, LOW> connectButton{ new Handler<App>(this, &App::onResetButtonRelease), ON_RELEASE };

  // Start button: only care about press
  // Switch 3: Digital pin 4 to 5V (active HIGH) - Active High Button
  PinSwitch<4, INPUT, HIGH> startButton{ new Handler<App>(this, &App::onStartButtonPress), ON_PRESS };

  // Keypad buttons: individual handlers per button using eventArg
  // Multi-switch on ADC - treat as buttons (press/release)
  // Resistor ladder: Multiple switches on A0 with different resistors
  PinMultiSwitch<A0, INPUT, 400, 300, 230, 180> keypadButtons{ new Handler<App>(this, &App::onKeypadButtonRelease), ON_RELEASE };

  // Status reporting
  RepeatTimer reportTimer{ 3000, new Handler<App>(this, &App::onReportTimer) };
  bool devicePowered = false;

public:
  App() {
    Serial.begin(9600);
    showStatus();
  }

  // Power switch handlers
  void onPowerSwitchActive(void* sender, CallbackInfo cbInfo) {
    if (cbInfo.eventType & ON_ACTIVE) {
      devicePowered = true;
      Serial.println("*** POWER ON ***");
      showStatus();
    }
    if (cbInfo.eventType & ON_INACTIVE) {
      devicePowered = false;
      Serial.println("*** POWER OFF ***");
      showStatus();
    }
  }
 
  // Reset button handlers
  void onResetButtonPress(void*, CallbackInfo) {
    Serial.println("Reset button PRESSED - preparing reset...");
  }

  void onResetButtonRelease(void*, CallbackInfo) {
    if (devicePowered) {
      Serial.println("Reset button RELEASED - executing reset!");
    } else {
      Serial.println("Reset ignored - device is off");
    }
  }

  // Start button handler (press only)
  void onStartButtonPress(void*, CallbackInfo) {
    if (devicePowered) {
      Serial.println("Start button PRESSED - beginning operation");
    } else {
      Serial.println("Start ignored - device is off");
    }
  }


  void onKeypadButtonRelease(void*, CallbackInfo info) {
    Serial.print("Keypad button ");
    Serial.print(info.eventArg);
    Serial.println(" RELEASED");
    Serial.print("  -> Action for button ");
    Serial.println(info.eventArg);
  }

  void onReportTimer(void*, CallbackInfo) {
    showStatus();
  }

  void showStatus() {
    Serial.println("\n--- System Status ---");
    Serial.print("Device: ");
    Serial.println(devicePowered ? "ON" : "OFF");
    Serial.print("Power switch: ");
    Serial.println(modeToggle.getValue() ? "ACTIVE (ON)" : "INACTIVE (OFF)");

    Serial.print("Reset button: ");
    Serial.println(connectButton.getValue() ? "PRESSED" : "released");

    Serial.print("Keypad active button: ");
    signed char val = keypadButtons.getValue();
    if (val > 0) {
      Serial.print("Button ");
      Serial.println(val);
    } else {
      Serial.println("none");
    }
    Serial.println("--------------------\n");
  }
};

void setup() {
  static App app;
}

void loop() {
  eva::tac();
}
