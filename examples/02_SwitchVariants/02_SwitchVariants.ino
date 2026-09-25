/**
 * EVA Core | EVA Survival Kit - Switch Initialization Variants
 * (no dynamic allocation, handlers placed next to their methods)
 */

#include <evaTac.h>
#include <evaSwitch.h>

using namespace eva;

class App
{
private:
  // === Custom reader for jumper bank ===
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
      return digitalRead(4) * 2 + digitalRead(5);
    }

    bool isValid()
    {
      return true;
    }
  };

  // ============================================================
  //  Handlers + their methods, kept next to each other
  //  (handlers declared first so switch objects below can use them)
  // ============================================================

  Handler<App> onToggleSwitchHandler{this, &App::onToggleSwitch};
  void onToggleSwitch(void *, CallbackInfo info)
  {
    Serial.print("Toggle switch (pin2): ");
    Serial.println(info.eventArg ? "ON" : "OFF");
  }

  Handler<App> onPushButtonPressHandler{this, &App::onPushButtonPress};
  void onPushButtonPress(void *, CallbackInfo)
  {
    Serial.println("Push button (pin3): PRESSED");
  }

  Handler<App> onActiveHighSwitchHandler{this, &App::onActiveHighSwitch};
  void onActiveHighSwitch(void *, CallbackInfo info)
  {
    Serial.print("Active HIGH switch (pin4): ");
    Serial.println(info.eventArg ? "ON" : "OFF");
  }

  Handler<App> onMultiPositionHandler{this, &App::onMultiPositionSwitch};
  void onMultiPositionSwitch(void *, CallbackInfo info)
  {
    Serial.print("Multi-position switch (A0): ");
    Serial.print("Position ");
    Serial.println(info.eventArg);
  }

  Handler<App> onMultiButtonHandler{this, &App::onMultiButtonRelease};
  void onMultiButtonRelease(void *, CallbackInfo info)
  {
    Serial.print("Multi-button pad (A1): Button ");
    Serial.print(info.eventArg);
    Serial.println(" released");
  }

  Handler<App> onJumperBankHandler{this, &App::onJumperBankChanged};
  void onJumperBankChanged(void *, CallbackInfo info)
  {
    Serial.print("Jumper bank (pins 4,5): Configuration ");
    Serial.println(info.eventArg);
  }

  // ============================================================
  //  Switch objects (reference the handlers above)
  // ============================================================

  // Simple toggle switch - reports both "ON" and "OFF" state changes
  PullUpSwitch<2> toggleSwitch{&onToggleSwitchHandler, ON_CHANGE};

  // Push button - reports only press events (release ignored)
  PullUpSwitch<3> pushButton{&onPushButtonPressHandler, ON_PRESS};

  // Active HIGH toggle - reports both "ON" and "OFF" state changes
  PinSwitch<4, INPUT, HIGH> activeHighSwitch{&onActiveHighSwitchHandler, ON_CHANGE};

  // Multi-position switch (e.g., rotary/selector) - reports which position is active
  PinMultiSwitch<A0, INPUT, 0, 200, 400, 600>
      multiPositionSwitch{&onMultiPositionHandler, ON_CHANGE};

  // Multiple buttons on a single ADC pin using resistor ladder.
  // First value (0) is reserved to indicate "inactive" state.
  PinMultiSwitch<A1, INPUT_PULLUP, 0, 200, 400, 600>
      multiButtonPad{&onMultiButtonHandler, ON_RELEASE};

  // Jumper bank (2 pins) - reports 2-bit configuration value (0-3) on any change
  Switch<DebounceDecor<JumpersBank>>
      jumperBank{&onJumperBankHandler, ON_CHANGE};
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