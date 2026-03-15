/**
 * eva Library - KeyButton Demo: Volume & Menu Navigation
 * 
 * Simple demonstration of KeyButton with auto-repeat:
 * - Volume Up/Down: Auto-repeat for fast tuning
 * - Menu navigation: Short press = move, Long press = select
 * 
 * Hardware connections (pull-up buttons to GND):
 * - Volume Up: pin 2
 * - Volume Down: pin 3
 * - Menu Up: pin 4
 * - Menu Down: pin 5
 * - Select: pin 6
 */

#include <evaTac.h>
#include <evaRepeatTimer.h>
#include <evaKeyButton.h>

using namespace eva;

// Application state
struct {
  unsigned char volume = 42;       // 0-100
  unsigned char menuPos = 0;       // 0-4 (5 menu items)
  bool menuActive = false;
  const char* menuItems[5] = {
    "Playback", "Equalizer", "Bluetooth", "Settings", "About"
  };
} state;

class App : public IHandler {
private:
  // KeyButtons with auto-repeat for volume
  KeyPullUpButton<2> volUpBtn;
  KeyPullUpButton<3> volDownBtn;
  
  // Regular buttons for menu (no repeat)
  PullUpButton<4> menuUpBtn;
  PullUpButton<5> menuDownBtn;
  PullUpButton<6> selectBtn;
  
  RepeatTimer displayTimer{500, this};  // Refresh display

public:
  App() {
    // Volume buttons: respond to both press and repeat
    volUpBtn.setListener(this, ON_PRESS | ON_REPEATKEY);
    volDownBtn.setListener(this, ON_PRESS | ON_REPEATKEY);
    
    // Menu buttons: only short clicks
    menuUpBtn.setListener(this, ON_SHORTCLICK);
    menuDownBtn.setListener(this, ON_SHORTCLICK);
    selectBtn.setListener(this, ON_SHORTCLICK | ON_LONGCLICK);
    
    Serial.begin(9600);
    showScreen();
  }
  
  void showScreen() {
    Serial.println("\033[2J\033[H");  // Clear screen
    Serial.println("=== KeyButton Demo ===");
    Serial.println("[Volume] UP:pin2 DOWN:pin3 (auto-repeat)");
    Serial.println("[Menu]   UP:pin4 DOWN:pin5 SELECT:pin6");
    Serial.println("------------------------");
    
    // Show volume bar
    Serial.print("Volume: [");
    for (int i = 0; i < 20; i++) {
      if (i < state.volume / 5) Serial.print('#');
      else Serial.print('-');
    }
    Serial.print("] ");
    Serial.print(state.volume);
    Serial.println("%");
    
    // Show menu
    Serial.println("\nMenu (long press Select to toggle):");
    if (state.menuActive) {
      for (int i = 0; i < 5; i++) {
        Serial.print(i == state.menuPos ? " > " : "   ");
        Serial.println(state.menuItems[i]);
      }
    } else {
      Serial.println("  [menu inactive]");
    }
    Serial.println("------------------------");
  }
  
  void invoke(void* sender, CallbackInfo info) override {
    // Volume control
    if (sender == &volUpBtn) {
      if (state.volume < 100) {
        state.volume += (info.eventType == ON_REPEATKEY) ? 5 : 1;
        if (state.volume > 100) state.volume = 100;
      }
    }
    else if (sender == &volDownBtn) {
      if (state.volume > 0) {
        state.volume -= (info.eventType == ON_REPEATKEY) ? 5 : 1;
        if (state.volume < 0) state.volume = 0;
      }
    }
    
    // Menu navigation (only when menu active)
    else if (sender == &menuUpBtn && state.menuActive) {
      if (state.menuPos > 0) state.menuPos--;
    }
    else if (sender == &menuDownBtn && state.menuActive) {
      if (state.menuPos < 4) state.menuPos++;
    }
    
    // Select button
    else if (sender == &selectBtn) {
      if (info.eventType == ON_LONGCLICK) {
        state.menuActive = !state.menuActive;
      } else if (info.eventType == ON_SHORTCLICK && state.menuActive) {
        Serial.print("Selected: ");
        Serial.println(state.menuItems[state.menuPos]);
      }
    }
    
    // Update display
    if (sender != &displayTimer) {
      showScreen();
    }
  }
};

App app;

void setup() {
  // Serial already initialized in App constructor
}

void loop() {
  eva::tac();
}
