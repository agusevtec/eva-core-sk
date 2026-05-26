#include <AUnit.h>
#include "MockReader.h"
#include "MockHandler.h"
#include <evaSwitch.h>

using namespace aunit;
using namespace eva;

using TestSwitch = Switch<MockReader>;

test(switch_starts_inactive)
{
    TestSwitch sw;
    assertEqual(sw.getValue(), 0);
}

test(switch_zero_is_no_button)
{
    TestSwitch btn;
    MockHandler handler;

    btn.setListener(&handler, ON_PRESS);

    btn.setValue(0);
    btn.tac();

    assertEqual(handler.callCount, 0);
    assertEqual(btn.getValue(), 0);
}

test(switch_detects_activation)
{
    TestSwitch sw;
    MockHandler handler;

    sw.setListener(&handler, ON_PRESS);
    sw.setValue(1);
    sw.tac();

    assertEqual(sw.getValue(), 1);
    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_PRESS);
}

test(switch_detects_deactivation)
{
    TestSwitch sw;
    MockHandler handler;

    sw.setListener(&handler, ON_RELEASE);

    sw.setValue(1);
    sw.tac();
    handler.reset();

    sw.setValue(0);
    sw.tac();

    assertEqual(sw.getValue(), 0);
    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_RELEASE);
}

test(switch_sends_change_event)
{
    TestSwitch sw;
    MockHandler handler;

    sw.setListener(&handler, ON_CHANGE);

    sw.setValue(1);
    sw.tac();
    assertEqual(handler.callCount, 1);

    sw.setValue(0);
    sw.tac();
    assertEqual(handler.callCount, 2);
}

test(switch_no_event_when_no_change)
{
    TestSwitch sw;
    MockHandler handler;

    sw.setListener(&handler, ON_PRESS);
    sw.setValue(1);
    sw.tac();
    assertEqual(handler.callCount, 1);

    handler.reset();
    sw.tac();
    assertEqual(handler.callCount, 0);
}

test(switch_can_be_disabled)
{
    TestSwitch sw;
    MockHandler handler;

    sw.setListener(&handler, ON_PRESS);
    sw.enable(false);

    sw.setValue(1);
    sw.tac();
    assertEqual(handler.callCount, 0);
    assertEqual(sw.getValue(), 0); 
}

test(switch_can_be_reenabled)
{
    TestSwitch sw;
    MockHandler handler;

    sw.setListener(&handler, ON_PRESS);
    sw.enable(false);

    sw.setValue(1);
    sw.tac();
    assertEqual(handler.callCount, 0);

    sw.enable(true);
    sw.tac();
    assertEqual(handler.callCount, 1);
    assertEqual(sw.getValue(), 1);
}

test(switch_detects_press_with_code)
{
    TestSwitch btn;
    MockHandler handler;

    btn.setListener(&handler, ON_PRESS);

    btn.setValue(3);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_PRESS);
    assertEqual((int)handler.lastArgs, 3);
    assertEqual(btn.getValue(), 3);
}

test(switch_detects_release_with_code)
{
    TestSwitch btn;
    MockHandler handler;

    btn.setListener(&handler, ON_RELEASE);

    btn.setValue(2);
    btn.tac();
    handler.reset();

    btn.setValue(0);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_RELEASE);
    assertEqual((int)handler.lastArgs, 2);
}

test(switch_switch_directly)
{
    TestSwitch btn;
    MockHandler handler;

    btn.setListener(&handler, ON_PRESS | ON_RELEASE);

    btn.setValue(1);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_PRESS);
    assertEqual((int)handler.lastArgs, 1);

    handler.reset();

    btn.setValue(2);
    btn.tac();

    assertEqual(handler.callCount, 2);
}

test(switch_switch_directly_onswitched)
{
    TestSwitch btn;
    MockHandler handler;

    btn.setListener(&handler, ON_CHANGE);

    btn.setValue(1);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_CHANGE);
    assertEqual((int)handler.lastArgs, 1);

    handler.reset();

    btn.setValue(2);
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_CHANGE);
    assertEqual((int)handler.lastArgs, 2);
}


test(switch_multiple_buttons)
{
    TestSwitch btn;
    MockHandler handler;

    btn.setListener(&handler, ON_PRESS);

    for (int code = 1; code <= 5; code++)
    {
        btn.setValue(code);
        btn.tac();

        assertEqual((int)handler.lastEventType, (int)ON_PRESS);
        assertEqual((int)handler.lastArgs, (int)code);
        assertEqual(btn.getValue(), code);

        handler.reset();
        btn.setValue(0);
        btn.tac();
    }
}

// NEW TESTS FOR isValid() FUNCTIONALITY
test(switch_does_not_update_state_on_invalid_read)
{
    TestSwitch sw;
    MockHandler handler;
    
    sw.setListener(&handler, ON_PRESS | ON_RELEASE);
    
    sw.setValue(1);
    sw.setValid(true);
    sw.tac();
    assertEqual(sw.getValue(), 1);
    assertEqual(handler.callCount, 1);
    
    handler.reset();
    sw.setValid(false);
    sw.setValue(0);
    sw.tac();
    assertEqual(sw.getValue(), 1);
    assertEqual(handler.callCount, 0);
}

test(switch_does_not_generate_events_during_invalid_period)
{
    TestSwitch sw;
    MockHandler handler;
    
    sw.setListener(&handler, ON_PRESS | ON_RELEASE);
    
    sw.setValue(1);
    sw.setValid(true);
    sw.tac();
    assertEqual(handler.callCount, 1);
    
    handler.reset();
    sw.setValid(false);
    sw.tac();
    assertEqual(handler.callCount, 0);
    
    sw.setValue(0);
    sw.tac();
    assertEqual(handler.callCount, 0);
    
    sw.setValid(true);
    sw.tac();
    assertEqual(sw.getValue(), 1);
    assertEqual(handler.callCount, 0);
}
