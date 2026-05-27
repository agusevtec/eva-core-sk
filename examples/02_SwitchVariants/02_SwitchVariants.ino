/**
 * eva Library - Switch Initialization Variants
 */

#include <evaTac.h>
#include <evaSwitch.h>

using namespace eva;

class App
{
private:
  // Simple toggle switch - reports both "ON" and "OFF" state changes
  PullupSwitch<2> toggleSwitch{new Handler<App>(this, &App::onToggleSwitch), ON_CHANGE};

  // Push button - reports only press events (release ignored)
  // With ON_PRESS | ON_RELEASE it behaves like a simple button (both press and release events)
  // When using ON_PRESS | ON_RELEASE, value 0 means no button is active
  PullupSwitch<3> pushButton{new Handler<App>(this, &App::onPushButtonPress), ON_PRESS};

  // Active HIGH toggle - reports both "ON" and "OFF" state changes
  PinSwitch<4, INPUT, HIGH> activeHighSwitch{new Handler<App>(this, &App::onActiveHighSwitch), ON_CHANGE};

  // Multi-position switch (e.g., rotary/selector) - reports which position is active
  PinMultiSwitch<A0, INPUT, 0, 200, 400, 600> multiPositionSwitch{new Handler<App>(this, &App::onMultiPositionSwitch), ON_CHANGE};

  // Multiple buttons on a single ADC pin using resistor ladder:
  //   ADC Pin  -----+--R1--+--R2--+--R3--+--R4--+
  //  (analog A1)    |      |      |      |      |
  //                  \      \      \      \      \
  //                 |      |      |      |      |
  //      GND   -----+------+------+------+------+
  //
  // Each button produces different ADC value when pressed/
  // Using ON_RELEASE to detect when button is released
  //
  // Note:
  // The first value in the list (here is 0) is reserved to indicate "inactive" state
  PinMultiSwitch<A1, INPUT_PULLUP, 0, 200, 400, 600> multiButtonPad{new Handler<App>(this, &App::onMultiButtonRelease), ON_RELEASE};

  // Custom reader that reads two jumper pins as a 2-bit value (0-3)
  class JumpersBank
  {
  public:
    JumpersBank()
    {
      pinMode(4, INPUT_PULLUP);
      pinMode(5, INPUT_PULLUP);
    }

    signed short getValue()
    {
      // Returns: 0,1,2,3 depending on jumper configuration
      return digitalRead(4) * 2 + digitalRead(5);
    }

    bool isValid()
    {
      return true;
    }
  };
  // Jumper bank (2 pins) - reports 2-bit configuration value (0-3) on any change
  Switch<DebounceDecor<JumpersBank>> jumperBank{new Handler<App>(this, &App::onJumperBankChanged), ON_CHANGE};

public:
  void onToggleSwitch(void *, CallbackInfo info)
  {
    Serial.print("Toggle switch (pin2): ");
    Serial.println(info.eventArg ? "ON" : "OFF");
  }

  void onPushButtonPress(void *, CallbackInfo)
  {
    Serial.println("Push button (pin3): PRESSED");
  }

  void onActiveHighSwitch(void *, CallbackInfo info)
  {
    Serial.print("Active HIGH switch (pin4): ");
    Serial.println(info.eventArg ? "ON" : "OFF");
  }

  void onMultiPositionSwitch(void *, CallbackInfo info)
  {
    Serial.print("Multi-position switch (A0): ");
    Serial.print("Position ");
    Serial.println(info.eventArg);
  }

  void onMultiButtonRelease(void *, CallbackInfo info)
  {
    Serial.print("Multi-button pad (A1): Button ");
    Serial.print(info.eventArg);
    Serial.println(" released");
  }

  void onJumperBankChanged(void *, CallbackInfo info)
  {
    Serial.print("Jumper bank (pins 4,5): Configuration ");
    Serial.println(info.eventArg);
  }
};

void setup()
{
  Serial.begin(9600);
  Serial.println("=== Switch Variants Demo ===");
  static App app;
}

void loop()
{
  eva::tac();
}