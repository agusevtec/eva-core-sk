#line 2 "SwitchTest.cpp"
#define protected public

#include <AUnit.h>
#include "MockReader.h"
#include "TestHandler.h"
#include <evaSwitch.h>

using namespace aunit;
using namespace eva;

// Тестируем Switch (Switch) - простой переключатель
using TestSwitch = Switch<MockReader>;

test(switch_starts_inactive) {
    TestSwitch sw;
    assertEqual(sw.getValue(), 0);
}

test(switch_detects_activation) {
    TestSwitch sw;
    TestHandler handler;
    
    sw.setListener(&handler, ON_ACTIVE);
    sw.setValue(1);
    sw.tick();
    
    assertEqual(sw.getValue(), 1);
    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_ACTIVE);
}

test(switch_detects_deactivation) {
    TestSwitch sw;
    TestHandler handler;
    
    sw.setListener(&handler, ON_INACTIVE);
    
    // Сначала активируем
    sw.setValue(1);
    sw.tick();
    handler.reset();
    
    // Потом деактивируем
    sw.setValue(0);
    sw.tick();
    
    assertEqual(sw.getValue(), 0);
    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_RELEASE);
}

test(switch_sends_change_event) {
    TestSwitch sw;
    TestHandler handler;
    
    sw.setListener(&handler, ON_ACTIVE|ON_INACTIVE);
    
    sw.setValue(1);
    sw.tick();
    assertEqual(handler.callCount, 1);
    
    sw.setValue(0);
    sw.tick();
    assertEqual(handler.callCount, 2);
}

test(switch_no_event_when_no_change) {
    TestSwitch sw;
    TestHandler handler;
    
    sw.setListener(&handler, ON_ACTIVE);
    sw.setValue(1);
    sw.tick();
    assertEqual(handler.callCount, 1);
    
    handler.reset();
    sw.tick(); // То же значение - нет события
    assertEqual(handler.callCount, 0);
}

test(switch_can_be_disabled) {
    TestSwitch sw;
    TestHandler handler;
    
    sw.setListener(&handler, ON_ACTIVE);
    sw.enable(false);
    
    sw.setValue(1);
    sw.tick();
    assertEqual(handler.callCount, 0);
    assertEqual(sw.getValue(), 0); // Не меняется когда disabled
}

test(switch_can_be_reenabled) {
    TestSwitch sw;
    TestHandler handler;
    
    sw.setListener(&handler, ON_ACTIVE);
    sw.enable(false);
    
    sw.setValue(1);
    sw.tick();
    assertEqual(handler.callCount, 0);
    
    sw.enable(true);
    sw.tick();
    assertEqual(handler.callCount, 1);
    assertEqual(sw.getValue(), 1);
}