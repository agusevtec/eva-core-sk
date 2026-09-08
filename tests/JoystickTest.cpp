#include <AUnit.h>
#include "MockReader.h"
#include <evaJoystick.h>

using namespace aunit;
using namespace eva;

test(joystick_can_work) {
    Joystick<MockReader, 0, 500, 1000> joystick;
    
    joystick.setValue(0);
    assertEqual(joystick.getValue(), -1000);

    joystick.setValue(1000);
    assertEqual(joystick.getValue(), 1000);

    joystick.setValue(750);
    assertMore(joystick.getValue(), 0);
    assertLess(joystick.getValue(), 1000);

    joystick.setValue(500);
    assertEqual(joystick.getValue(), 0);

    joystick.setTrim(50);
    assertEqual(joystick.getValue(), 50);
}

test(joystick_can_reverse) {
    Joystick<MockReader, 1000, 500, 0> joystick;
    
    joystick.setValue(1000);
    assertEqual(joystick.getValue(), -1000);

    joystick.setValue(0);
    assertEqual(joystick.getValue(), 1000);

    joystick.setValue(250);
    assertMore(joystick.getValue(), 0);
    assertLess(joystick.getValue(), 1000);

    joystick.setValue(500);
    assertEqual(joystick.getValue(), 0);

    joystick.setTrim(50);
    assertEqual(joystick.getValue(), 50);

}

test(joystick_deadZone)
{
    Joystick<MockReader, 0, 500, 1000> joystick;
    joystick.setDeadZone(100);
    joystick.setValue(520);
    assertEqual(joystick.getValue(), 0);
    joystick.setValue(600);
    assertMore(joystick.getValue(), 0);

    joystick.setValue(480);
    assertEqual(joystick.getValue(), 0);
    joystick.setValue(400);
    assertLess(joystick.getValue(), 0);

}

test(joystick_deadZone_reversed)
{
    Joystick<MockReader, 1000, 500, 0> joystick;
    joystick.setDeadZone(100);
    joystick.setValue(520);
    assertEqual(joystick.getValue(), 0);
    joystick.setValue(600);
    assertLess(joystick.getValue(), 0);

    joystick.setValue(480);
    assertEqual(joystick.getValue(), 0);
    joystick.setValue(400);
    assertMore(joystick.getValue(), 0);

}

#include <iostream>
test(joystick_deadZone2)
{
    Joystick<MockReader, 1000, 500, 0> joystick;
    joystick.setDeadZone(100);
    joystick.setTrim(50);
    for (int i = 1000; i > 0; i-=10)
    {
        joystick.setValue(i);
        std::cout<< i << " " << joystick.getValue() << "\n";
    }
}