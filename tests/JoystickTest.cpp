#include <AUnit.h>
#include "MockReader.h"
#include <evaJoystick.h>

using namespace aunit;
using namespace eva;

test(joystick_returns_0_at_center) {
    Joystick<MockReader, 0, 512, 1023> joystick;
    joystick.setTrim(0);
    
    joystick.setValue(512);
    assertEqual(joystick.getValue(), 0);
}

test(joystick_returns_positive_for_higher_values) {
    Joystick<MockReader, 0, 512, 1023> joystick;
    joystick.setTrim(0);
    
    joystick.setValue(768);
    int result = joystick.getValue();
    assertMore(result, 0);
    assertLess(result, 128);
}

test(joystick_returns_negative_for_lower_values) {
    Joystick<MockReader, 0, 512, 1023> joystick;
    joystick.setTrim(0);
    
    joystick.setValue(256);
    int result = joystick.getValue();
    assertLess(result, 0);
    assertMore(result, -128);
}

test(joystick_returns_127_at_max) {
    Joystick<MockReader, 0, 512, 1023> joystick;
    joystick.setTrim(0);
    
    joystick.setValue(1023);
    assertEqual(joystick.getValue(), 127);
}

test(joystick_returns_minus127_at_min) {
    Joystick<MockReader, 0, 512, 1023> joystick;
    joystick.setTrim(0);
    
    joystick.setValue(0);
    assertEqual(joystick.getValue(), -127);
}

test(joystick_trim_affects_output) {
    Joystick<MockReader, 0, 512, 1023> joystick;
    
    joystick.setTrim(50);
    assertEqual(joystick.getTrim(), 50);
    
    joystick.setTrim(30);
    assertEqual(joystick.getTrim(), 30);
}