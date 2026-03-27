
#include <AUnit.h>
#include <evaHeartbeat.h>
#include <evaTac.h>

using namespace aunit;
using namespace eva;

class TestHeartbeat : public Heartbeat {
public:
    int heartbeatCount = 0;
    unsigned long lastBeatMs = 0;
    
    TestHeartbeat(unsigned long periodMs) : Heartbeat(periodMs) {}
    
protected:
    void onHeartbeat() override {
        heartbeatCount++;
        lastBeatMs = millis();
    }
};

test(heartbeat_not_fires_before_period) {
    TestHeartbeat hb(100);
    
    hb.heartbeatCount = 0;
    
    delay(50);
    eva::tac();
    assertEqual(hb.heartbeatCount, 0);
    
    delay(40);
    eva::tac();
    assertEqual(hb.heartbeatCount, 0);
}

test(heartbeat_fires_after_period) {
    TestHeartbeat hb(100);
    
    hb.heartbeatCount = 0;
    
    delay(100);
    eva::tac();
    assertEqual(hb.heartbeatCount, 1);
    
    delay(50);
    eva::tac();
    assertEqual(hb.heartbeatCount, 1);
    
    delay(50);
    eva::tac();
    assertEqual(hb.heartbeatCount, 2);
}


test(heartbeat_multiple_objects) {
    TestHeartbeat hb1(50);
    TestHeartbeat hb2(100);
    
    hb1.heartbeatCount = 0;
    hb2.heartbeatCount = 0;
    
    delay(50);
    eva::tac();
    assertEqual(hb1.heartbeatCount, 1);
    assertEqual(hb2.heartbeatCount, 0);
    
    delay(50);
    eva::tac();
    assertEqual(hb1.heartbeatCount, 2);
    assertEqual(hb2.heartbeatCount, 1);
}

test(heartbeat_precise_timing) {
    TestHeartbeat hb(50);
    
    hb.heartbeatCount = 0;
    
    delay(50);
    eva::tac();
    assertEqual(hb.heartbeatCount, 1);
    
    delay(40);
    eva::tac();
    assertEqual(hb.heartbeatCount, 1);
    
    delay(20);
    eva::tac();
    assertEqual(hb.heartbeatCount, 2);
}

test(heartbeat_multiple_in_chain) {
    TestHeartbeat hb1(50);
    TestHeartbeat hb2(100);
    TestHeartbeat hb3(150);
    
    hb1.heartbeatCount = 0;
    hb2.heartbeatCount = 0;
    hb3.heartbeatCount = 0;
    
    delay(50);
    eva::tac();
    assertEqual(hb1.heartbeatCount, 1);
    assertEqual(hb2.heartbeatCount, 0);
    assertEqual(hb3.heartbeatCount, 0);
    
    delay(50);
    eva::tac();
    assertEqual(hb1.heartbeatCount, 2);
    assertEqual(hb2.heartbeatCount, 1);
    assertEqual(hb3.heartbeatCount, 0);
    
    delay(50);
    eva::tac();
    assertEqual(hb1.heartbeatCount, 3);
    assertEqual(hb2.heartbeatCount, 1);
    assertEqual(hb3.heartbeatCount, 1);
}

test(heartbeat_minimal_period) {
    TestHeartbeat hb(1); // Самый маленький период
    
    hb.heartbeatCount = 0;
    
    delay(1);
    eva::tac();
    assertTrue(hb.heartbeatCount >= 1);
}

test(heartbeat_no_extra_calls) {
    TestHeartbeat hb(100);
    
    hb.heartbeatCount = 0;
    
    // Вызываем tac() много раз за короткое время
    for (int i = 0; i < 10; i++) {
        delay(5);
        eva::tac();
    }
    
    assertEqual(hb.heartbeatCount, 0);
    
    delay(100);
    eva::tac();
    assertEqual(hb.heartbeatCount, 1);
}
