#include <AUnit.h>
#include "MockReader.h"
#include "MockHandler.h"
#include <evaButton.h>

using namespace aunit;
using namespace eva;

using TestButton = Button<MockReader>;

test(button_detects_press)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_PRESS);
    btn.setValue(0);
    btn.tac();
    btn.setValue(1);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_PRESS);
}
test(button_detects_release)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_RELEASE);

    btn.setValue(1);
    btn.tac();
    handler.reset();

    delay(100);

    btn.setValue(0);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_RELEASE);
}

test(button_short_click)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_SHORTCLICK);

    btn.setValue(1);
    btn.tac();

    // Less than 750 ms
    delay(500);

    btn.setValue(0);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_SHORTCLICK);
}

test(button_long_click)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_LONGCLICK);

    btn.setValue(1);
    btn.tac();

    // more than 750ms
    delay(800);

    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_LONGCLICK);
}

test(button_no_short_click_after_long)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_SHORTCLICK | ON_LONGCLICK);

    btn.setValue(1);
    btn.tac();
    handler.reset();

    // more than 750ms
    delay(800);
    btn.tac(); 
    assertEqual((int)handler.lastEventType, (int)ON_LONGCLICK);

    handler.reset();

    btn.setValue(0);
    btn.tac();
    assertEqual(handler.callCount, 0);
}


test(button_can_be_disabled)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_PRESS);
    btn.enable(false);

    btn.setValue(1);
    btn.tac();
    assertEqual(handler.callCount, 0);
}

test(button_short_click_with_code)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_SHORTCLICK);

    btn.setValue(4);
    btn.tac();
    delay(500); // less than 750ms

    btn.setValue(0);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_SHORTCLICK);
    assertEqual((int)handler.lastArgs, 4);
}

test(button_long_click_with_code)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_LONGCLICK);

    btn.setValue(1);
    btn.tac();
    delay(800); // more than 750 ms

    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_LONGCLICK);
    assertEqual((int)handler.lastArgs, 1);
}
