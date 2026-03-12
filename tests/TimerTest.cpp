// TimerTests.ino
#include <AUnit.h>
#include <evaDelayTimer.h>
#include <evaRepeatTimer.h>
#include "MockHandler.h"

using namespace aunit;
using namespace eva;

MockHandler handler;

// -------------------------------------------------------------------
// DelayTimer
// -------------------------------------------------------------------

test(delayTimer_triggers_once) {
    handler.reset();
    DelayTimer timer;

    timer.start(190, &handler);

    delay(100);
    timer.tac();
    assertEqual(handler.callCount, 0);

    delay(100);
    timer.tac();
    assertEqual(handler.callCount, 1);
    assertEqual(handler.lastSender, &timer);

    timer.tac();
    assertEqual(handler.callCount, 1);
}

test(delayTimer_stop_prevents_trigger) {
    handler.reset();
    DelayTimer timer;

    timer.start(200, &handler);
    timer.stop();

    delay(250);
    timer.tac();
    assertEqual(handler.callCount, 0);
}

test(delayTimer_restart_resets_timer) {
    handler.reset();
    DelayTimer timer;

    timer.start(190, &handler);
    delay(100);
    timer.tac();

    timer.start(90, &handler);
    delay(50);
    timer.tac();
    assertEqual(handler.callCount, 0);

    delay(60);
    timer.tac();
    assertEqual(handler.callCount, 1);
}

test(delayTimer_multiple_in_chain) {
    handler.reset();
    DelayTimer t1, t2;
    
    t1.start(90, &handler);
    t2.start(190, &handler);
    
    delay(150);
    t1.tac();
    
    t1.tac();
    t2.tac();
    
    assertEqual(handler.callCount, 1);
    
    delay(100);
    t1.tac();
    t2.tac();
    assertEqual(handler.callCount, 2);
}

// -------------------------------------------------------------------
// RepeatTimer
// -------------------------------------------------------------------
test(repeatTimer_triggers_periodically) {
    handler.reset();
    RepeatTimer timer(140, &handler);

    delay(150);
    timer.tac();                    
    assertEqual(handler.callCount, 1);

    delay(150);
    timer.tac();
    assertEqual(handler.callCount, 2);

    delay(150);
    timer.tac();
    assertEqual(handler.callCount, 3);
}

test(repeatTimer_stop_stops) {
    handler.reset();
    RepeatTimer timer(140, &handler);

    delay(150);
    timer.tac();
    assertEqual(handler.callCount, 1);

    timer.stop();

    delay(300);
    timer.tac();
    assertEqual(handler.callCount, 1);
}

test(repeatTimer_can_be_restarted) {
    handler.reset();
    RepeatTimer timer(190, &handler);

    delay(200);
    timer.tac();
    assertEqual(handler.callCount, 1);

    timer.start(90, &handler);
    handler.reset();

    delay(100);
    timer.tac();
    assertEqual(handler.callCount, 1);

    delay(100);
    timer.tac();
    assertEqual(handler.callCount, 2);
}

