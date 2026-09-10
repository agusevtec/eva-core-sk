/**
 * eva Library - RingBuffer Container Example
 * 
 * Simple demonstration of eva::RingBuffer container capabilities:
 * - Fixed capacity static allocation
 * - Adding elements (put)
 * - Checking size, full and empty status
 * - Reading elements by relative index
 * - Buffer overflow and automatic overwrite (wrap-around)
 * - Storing custom structs
 */

#include <evaRingBuffer.h>

using namespace eva;

struct Reading {
  int sensorId;
  int rawValue;
};

void demonstrateBasicOperations() {
  Serial.println("1. Creating RingBuffer (Capacity = 4):");
  RingBuffer<int, 4> buffer;

  Serial.print("   isEmpty: "); Serial.println(buffer.isEmpty() ? "true" : "false");
  Serial.print("   isFull:  "); Serial.println(buffer.isFull() ? "true" : "false");
  Serial.print("   size:    "); Serial.println(buffer.size());

  Serial.println("\n2. Pushing items into buffer:");
  buffer.put(10);
  buffer.put(20);
  buffer.put(30);

  Serial.print("   size after 3 puts: "); Serial.println(buffer.size());
  Serial.print("   isEmpty:           "); Serial.println(buffer.isEmpty() ? "true" : "false");
  Serial.print("   isFull:            "); Serial.println(buffer.isFull() ? "true" : "false");

  Serial.println("\n3. Accessing items by relative index (0 = oldest):");
  for (unsigned char i = 0; i < buffer.size(); i++) {
    Serial.print("   buffer.get(");
    Serial.print(i);
    Serial.print(") = ");
    Serial.println(buffer.get(i));
  }
}

void demonstrateOverflowAndWrapAround() {
  Serial.println("\n4. Filling to capacity and testing overflow:");
  RingBuffer<int, 3> buffer;

  buffer.put(100);
  buffer.put(200);
  buffer.put(300);

  Serial.print("   Filled 3 items. isFull: ");
  Serial.println(buffer.isFull() ? "true" : "false");

  for (unsigned char i = 0; i < buffer.size(); i++) {
    Serial.print("   ["); Serial.print(i); Serial.print("]: ");
    Serial.println(buffer.get(i));
  }

  Serial.println("\n   Putting 4th item (400) - overwrites oldest item (100):");
  buffer.put(400);

  Serial.print("   size (remains max capacity): ");
  Serial.println(buffer.size());

  for (unsigned char i = 0; i < buffer.size(); i++) {
    Serial.print("   ["); Serial.print(i); Serial.print("]: ");
    Serial.println(buffer.get(i));
  }
}

void demonstrateCustomStructBuffer() {
  Serial.println("\n5. RingBuffer of custom structs:");
  RingBuffer<Reading, 3> sensorLog;

  sensorLog.put({1, 512});
  sensorLog.put({2, 768});
  sensorLog.put({3, 1024});

  for (unsigned char i = 0; i < sensorLog.size(); i++) {
    Reading r = sensorLog.get(i);
    Serial.print("   Log [");
    Serial.print(i);
    Serial.print("] -> Sensor ID: ");
    Serial.print(r.sensorId);
    Serial.print(", Value: ");
    Serial.println(r.rawValue);
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("=== RingBuffer Container Demo ===\n");

  demonstrateBasicOperations();
  demonstrateOverflowAndWrapAround();
  demonstrateCustomStructBuffer();

  Serial.println("\n=== Demo Complete ===");
}

void loop() {
  // Nothing to do here - demo runs once in setup
}
