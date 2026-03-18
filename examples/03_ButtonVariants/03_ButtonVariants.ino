/**
 * eva Library - Button Initialization Variants
 */

#include <evaTac.h>
#include <evaButton.h>

using namespace eva;

class App
{
private:
  // Button on pin6 (pull-up) - detects both short clicks and long presses
  // This is the most common and convenient usage pattern for buttons
  PullUpButton<2> button1{new Handler<App>(this, &App::onButton1ShortClickOrLongpress), ON_SHORTCLICK | ON_LONGPRESS};

  // Button on pin7 (active HIGH) - detects press events only
  PinButton<3, INPUT, LOW> button2{new Handler<App>(this, &App::onButton2Press), ON_PRESS};

  // Multiple buttons on a single ADC pin using resistor ladder:
  //   ADC Pin  -----+--R1--+--R2--+--R3--+--R4--+
  //  (analog A1)    |      |      |      |      |
  //                  \      \      \      \      \
  //                 |      |      |      |      |
  //      GND   -----+------+------+------+------+
  //
  // Each button produces different ADC value when pressed/
  // Using ON_RELEASE to detect when button is released
  PinMultiButton<A0, INPUT, 0, 200, 400, 600> multiPad{new Handler<App>(this, &App::onMultiPadPress), ON_PRESS};

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
  };
  // Custom 4-direction keypad with debouncing - returns 'u','d','l','r' on press
  Button<DebounceDecor<MyKeyPad>> navPad{new Handler<App>(this, &App::onNavPadPress), ON_PRESS};

public:
  void onButton1ShortClickOrLongpress(void *, CallbackInfo info)
  {
    if (info.eventType == ON_SHORTCLICK)
      Serial.println("Button1: short click");
    else if (info.eventType == ON_LONGPRESS)
      Serial.println("Button1: long press");
  }

  void onButton2Press(void *, CallbackInfo)
  {
    Serial.println("Button2: pressed");
  }

  void onMultiPadPress(void *, CallbackInfo info)
  {
    Serial.print("MultiPad button ");
    Serial.println(info.eventArg);
  }

  void onNavPadPress(void *, CallbackInfo info)
  {
    Serial.print("NavPad button ");
    Serial.println((char)info.eventArg);
  }
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
