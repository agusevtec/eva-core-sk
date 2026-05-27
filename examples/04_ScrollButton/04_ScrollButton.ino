/**
 * eva Library - ScrollButton with Custom KeyPad Demo
 *
 * Two input methods:
 * 1. Volume control with PullUpScrollButton (auto-repeat)
 * 2. Navigation pad with custom 4-direction reader
 */

#include <evaTac.h>
#include <evaScrollButton.h>

using namespace eva;

class App {
private:
  /** @brief Scroll button for volume up with auto-repeat on hold */
  PullupScrollButton<2> volPlus{ &onVolumeButtonPressedHandler, ON_PRESS | ON_REPEATKEY };
  
  /** @brief Scroll button for volume down with auto-repeat on hold */
  PullupScrollButton<3> volMinus{ &onVolumeButtonPressedHandler, ON_PRESS | ON_REPEATKEY };

  /**
   * @brief Custom reader for 2-direction navigation pad
   * 
   * Returns 'L' when left button (pin4) is pressed,
   * 'R' when right button (pin5) is pressed,
   * 0 when no button is pressed.
   */
  class NavPadReader {
  public:
    NavPadReader() {
      pinMode(4, INPUT_PULLUP);
      pinMode(5, INPUT_PULLUP);
    }

    signed short getValue() {
      if (digitalRead(4) == LOW)
        return 'L';  // Left
      if (digitalRead(5) == LOW)
        return 'R';  // Right
      return 0;      // No button pressed
    }
    
    bool isValid()
    {
      return true;
    }
  };
  
  /** @brief Scroll button for menu navigation using custom keypad reader */
  ScrollButton<NavPadReader> navigationKeypad{&onNavigationKeypadPressedHandler, ON_PRESS | ON_REPEATKEY };

  unsigned char volume = 10;
  unsigned char menuPos = 0;

public:

  Handler<App> onVolumeButtonPressedHandler{ this, &App::onVolumeButtonPressed };
  void onVolumeButtonPressed(void *sender, CallbackInfo info) {
    int delta = (sender == &volPlus) ? 1 : -1;
    volume = constrain(volume + delta, 0, 10);
    Serial.print("Volume: ");
    Serial.println(volume);
  }

  Handler<App> onNavigationKeypadPressedHandler{ this, &App::onNavigationKeypadPressed };
  void onNavigationKeypadPressed(void *sender, CallbackInfo info) {
    switch (info.eventArg) {
      case 'L': menuPos--; break;
      case 'R': menuPos++; break;
      default: return;
    }
    menuPos = constrain(menuPos, 0, 10);

    Serial.print("Menu option: ");
    Serial.println(menuPos);
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
  Serial.println("=== ScrollButton Demo ===");
}

void loop() {
  eva::tac();
}