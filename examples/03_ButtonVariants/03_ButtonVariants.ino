/**
 * EVA Core | EVA Survival Kit - Button Initialization Variants
 * (no dynamic allocation, handlers placed next to their methods)
 */

#include <evaTac.h>
#include <evaButton.h>

using namespace eva;

class App
{
private:
  // === Custom 4-direction keypad reader ===
  class MyKeyPad
  {
  public:
    MyKeyPad()
    {
      pinMode(4, INPUT_PULLUP);
      pinMode(5, INPUT_PULLUP);
      pinMode(6, INPUT_PULLUP);
      pinMode(7, INPUT_PULLUP);
    }

    signed short getValue()
    {
      if (digitalRead(2) == LOW)
        return 'u';
      if (digitalRead(3) == LOW)
        return 'd';
      if (digitalRead(4) == LOW)
        return 'l';
      if (digitalRead(5) == LOW)
        return 'r';
      return 0;
    }

    bool isValid()
    {
      return true;
    }
  };

  // ============================================================
  //  Handlers + their methods, kept next to each other
  //  (handlers declared first so button objects below can use them)
  // ============================================================

  // Button on pin2 (pull-up) - detects both short clicks and long presses
  // This is the most common and convenient usage pattern for buttons
  Handler<App> onButton1ShortClickOrLongpressHandler{this, &App::onButton1ShortClickOrLongpress};
  void onButton1ShortClickOrLongpress(void *, CallbackInfo info)
  {
    if (info.eventType == ON_SHORTCLICK)
      Serial.println("Button1: short click");
    else if (info.eventType == ON_LONGPRESS)
      Serial.println("Button1: long press");
  }

  // Button on pin3 (active HIGH) - detects press events only
  Handler<App> onButton2PressHandler{this, &App::onButton2Press};
  void onButton2Press(void *, CallbackInfo)
  {
    Serial.println("Button2: pressed");
  }

  // Multiple buttons on a single ADC pin using resistor ladder
  Handler<App> onMultiPadPressHandler{this, &App::onMultiPadPress};
  void onMultiPadPress(void *, CallbackInfo info)
  {
    Serial.print("MultiPad button ");
    Serial.println(info.eventArg);
  }

  // Custom 4-direction keypad with debouncing - returns 'u','d','l','r' on press
  Handler<App> onNavPadPressHandler{this, &App::onNavPadPress};
  void onNavPadPress(void *, CallbackInfo info)
  {
    Serial.print("NavPad button ");
    Serial.println((char)info.eventArg);
  }

  // Button on pin2 (pull-up) - detects both short clicks and long presses
  PullUpButton<2> button1{&onButton1ShortClickOrLongpressHandler, ON_SHORTCLICK | ON_LONGPRESS};

  // Button on pin3 (active HIGH) - detects press events only
  PinButton<3, INPUT, LOW> button2{&onButton2PressHandler, ON_PRESS};

  // Multiple buttons on a single ADC pin using resistor ladder:
  //   ADC Pin  -----+--R1--+--R2--+--R3--+--R4--+
  //  (analog A0)    |      |      |      |      |
  //                  \      \      \      \      \
  //                 |      |      |      |      |
  //      GND   -----+------+------+------+------+
  //
  // Each button produces different ADC value when pressed.
  // First value (0) is reserved to indicate "inactive" state.
  PinMultiButton<A0, INPUT, 0, 200, 400, 600> multiPad{&onMultiPadPressHandler, ON_PRESS};

  // Custom 4-direction keypad with debouncing
  Button<DebounceDecor<MyKeyPad>> navPad{&onNavPadPressHandler, ON_PRESS};
};

void setup()
{
  Serial.begin(9600);
  Serial.println("=== Button Variants Demo ===");
  static App app;
}

void loop()
{
  eva::tac();
}