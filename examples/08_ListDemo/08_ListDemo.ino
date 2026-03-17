/**
 * eva Library - List Container Example
 * 
 * Simple demonstration of eva::List container capabilities:
 * - Creating lists
 * - Appending items
 * - Accessing by index
 * - Iterating through items
 * - Finding items
 * - Removing items
 * - Copying lists
 * 
 * MEMORY WARNING: List uses dynamic allocation (new/delete).
 * Frequent add/remove operations cause memory fragmentation.
 * Best used for one-time initialization or rarely changing data.
 */

#include <evaList.h>

using namespace eva;

struct Sensor {
  int id;
  int value;
  
  bool operator==(const Sensor& other) const {
    return id == other.id;
  }
};

void demonstrateIntegerList() {
  Serial.println("1. Creating integer list:");
  List<int> numbers;
  numbers.append(10);
  numbers.append(20);
  numbers.append(30);
  numbers.append(40);
  Serial.print("   Count: "); Serial.println(numbers.count());
  
  Serial.println("\n2. Access by index:");
  for (int i = 0; i < numbers.count(); i++) {
    Serial.print("   numbers[");
    Serial.print(i);
    Serial.print("] = ");
    Serial.println(*numbers[i]);
  }
  
  Serial.println("\n3. Iterating with ListIterator:");
  int index = 0;
  for (auto iter = numbers.first(); iter != nullptr; iter = iter->next) {
    Serial.print("   Item ");
    Serial.print(index++);
    Serial.print(": ");
    Serial.println(iter->item);
  }
  
  Serial.println("\n4. Finding items:");
  int searchFor = 30;
  int pos = numbers.indexOf(searchFor);
  if (pos >= 0) {
    Serial.print("   Found ");
    Serial.print(searchFor);
    Serial.print(" at index ");
    Serial.println(pos);
  } else {
    Serial.print("   ");
    Serial.print(searchFor);
    Serial.println(" not found");
  }
  
  Serial.println("\n5. Removing items:");
  Serial.print("   Before removal - count: ");
  Serial.println(numbers.count());
  numbers.removeAt(1);
  Serial.print("   After removal - count: ");
  Serial.println(numbers.count());
  
  for (int i = 0; i < numbers.count(); i++) {
    Serial.print("   numbers[");
    Serial.print(i);
    Serial.print("] = ");
    Serial.println(*numbers[i]);
  }
}

void demonstrateCustomStructList() {
  Serial.println("\n6. List of custom structs:");
  List<Sensor> sensors;
  sensors.append({1, 423});
  sensors.append({2, 567});
  sensors.append({3, 345});
  
  for (auto sIter = sensors.first(); sIter != nullptr; sIter = sIter->next) {
    Serial.print("   Sensor ID ");
    Serial.print(sIter->item.id);
    Serial.print(": value ");
    Serial.println(sIter->item.value);
  }
}

void demonstrateListCopying() {
  Serial.println("\n7. Copy constructor and assignment:");
  List<int> original;
  original.append(10);
  original.append(20);
  original.append(30);
  
  List<int> copy1(original);
  List<int> copy2;
  copy2 = original;
  
  Serial.print("   Original count: ");
  Serial.println(original.count());
  Serial.print("   Copy1 count: ");
  Serial.println(copy1.count());
  Serial.print("   Copy2 count: ");
  Serial.println(copy2.count());
  
  original.append(99);
  Serial.println("\n   After adding 99 to original:");
  Serial.print("   Original count: ");
  Serial.println(original.count());
  Serial.print("   Copy1 count (unchanged): ");
  Serial.println(copy1.count());
}

void demonstrateListClearing() {
  Serial.println("\n8. Clearing lists:");
  List<int> numbers;
  numbers.append(10);
  numbers.append(20);
  numbers.append(30);
  
  Serial.print("   Before clear - count: ");
  Serial.println(numbers.count());
  numbers.clear();
  Serial.print("   After clear - count: ");
  Serial.println(numbers.count());
  Serial.println(numbers.isEmpty() ? "   List is empty" : "   List not empty");
}

void setup() {
  Serial.begin(9600);
  Serial.println("=== List Container Demo ===\n");
  
  demonstrateIntegerList();
  demonstrateCustomStructList();
  demonstrateListCopying();
  demonstrateListClearing();
  
  Serial.println("\n=== Demo Complete ===");
}

void loop() {
  // Nothing to do here - demo runs once in setup
}