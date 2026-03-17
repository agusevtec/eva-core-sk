<09_TickableComparison.ino>
/**
 * eva Library - Timer vs Tickable Comparison
 * 
 * Two components with identical functionality (ramp wave 0-255):
 * - ComponentV1: Uses RepeatTimer for periodic updates
 * - ComponentV2: Uses Tickable inheritance for periodic updates
 */

#include <evaTac.h>
#include <evaTickable.h>
#include <evaRepeatTimer.h>
#include <evaHandler.h>

using namespace eva;

/**
 * @brief Component using RepeatTimer for periodic updates (50Hz)
 */
class ComponentV1 {
private:
  unsigned char value = 0;
  RepeatTimer updateTimer{20, new Handler<ComponentV1>(this, &ComponentV1::onUpdateTimer)};

public:
  ComponentV1() {
    Serial.println("ComponentV1: Updated via RepeatTimer (50Hz)");
  }

  unsigned char getValue() { return value; }

private:
  void onUpdateTimer(void*, CallbackInfo) {
    value++;
  }
};

/**
 * @brief Component using Tickable inheritance for periodic updates (50Hz)
 */
class ComponentV2 : public Tickable {
private:
  unsigned char value = 0;
  unsigned long lastUpdate = 0;
  const unsigned short interval = 20;

public:
  ComponentV2() {
    Serial.println("ComponentV2: Updated via Tickable::tick() (50Hz)");
  }

  unsigned char getValue() { return value; }

protected:
  void tick() override {
    unsigned long now = millis();
    if (now - lastUpdate >= interval) {
      value++;
      lastUpdate = now;
    }
  }
};

void setup() {
  Serial.begin(9600);
  Serial.println("\n=== Timer vs Tickable Comparison ===\n");
  static ComponentV1 comp1;
  static ComponentV2 comp2;
}

void loop() {
  eva::tac();  // Updates ComponentV2 (Tickable) and ComponentV1's timer
}