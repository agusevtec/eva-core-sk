/**
 * eva Library - List Container Example
 * 
 * Simple demonstration of eva::List:
 * - Store sensor readings
 * - Add new readings with button
 * - Display all readings periodically
 */

#include <evaTac.h>
#include <evaList.h>
#include <evaButton.h>
#include <evaRepeatTimer.h>

using namespace eva;

struct SensorReading {
  unsigned short id;
  unsigned short value;
  
  bool operator==(const SensorReading& other) const {
    return id == other.id;
  }
};

class App : public IHandler {
private:
  PullUpButton<2> addButton;           // Add new reading
  List<SensorReading> readings;         // List of readings
  RepeatTimer displayTimer{5000, this}; // Show list every 5s
  unsigned short nextId = 1;

public:
  App() {
    addButton.setListener(this, ON_PRESS);
    
    // Add some initial readings
    readings.append({1, 423});
    readings.append({2, 567});
    readings.append({3, 345});
    
    Serial.println("List Demo: Press button to add readings");
    showList();
  }
  
  void showList() {
    Serial.println("\n--- Sensor Readings ---");
    if (readings.isEmpty()) {
      Serial.println("  [empty]");
    } else {
      ListIterator<SensorReading>* iter = readings.first();
      while (iter) {
        Serial.print("  Sensor ");
        Serial.print(iter->item.id);
        Serial.print(": ");
        Serial.println(iter->item.value);
        iter = iter->next;
      }
    }
    Serial.print("Total: ");
    Serial.println(readings.count());
  }
  
  void invoke(void* sender, CallbackInfo info) override {
    if (sender == &addButton) {
      SensorReading newReading = {nextId++, random(200, 1000)};
      readings.append(newReading);
      Serial.print("Added: Sensor ");
      Serial.println(newReading.id);
    }
    else if (sender == &displayTimer) {
      showList();
    }
  }
};

App app;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  eva::tac();
}
