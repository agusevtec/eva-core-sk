#include <AUnit.h>
#include "MockReader.h"
#include <evaJoystick.h>

using namespace aunit;
using namespace eva;

test(joystick_can_work) {
    Joystick<MockReader, 0, 500, 1000> joystick;
    
    joystick.setValue(0);
    assertEqual(joystick.getValue(), -127);

    joystick.setValue(1000);
    assertEqual(joystick.getValue(), 127);

    joystick.setValue(750);
    assertMore(joystick.getValue(), 0);
    assertLess(joystick.getValue(), 127);

    joystick.setValue(500);
    assertEqual(joystick.getValue(), 0);

    joystick.setTrim(50);
    assertEqual(joystick.getValue(), 50);
}

test(joystick_can_reverse) {
    Joystick<MockReader, 1000, 500, 0> joystick;
    
    joystick.setValue(1000);
    assertEqual(joystick.getValue(), -127);

    joystick.setValue(0);
    assertEqual(joystick.getValue(), 127);

    joystick.setValue(250);
    assertMore(joystick.getValue(), 0);
    assertLess(joystick.getValue(), 127);

    joystick.setValue(500);
    assertEqual(joystick.getValue(), 0);

    joystick.setTrim(50);
    assertEqual(joystick.getValue(), 50);

}