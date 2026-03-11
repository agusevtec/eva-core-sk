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

    timer.start(200, &handler);

    delay(100);
    timer.tac();                    // 👈 легально!
    assertEqual(handler.callCount, 0);

    delay(100);
    timer.tac();                    // 👈 легально!
    assertEqual(handler.callCount, 1);
    assertEqual(handler.lastSender, &timer);

    timer.tac();                    // ещё раз — не должно повториться
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

    timer.start(200, &handler);
    delay(100);
    timer.tac();                      // не сработал

    timer.start(100, &handler);       // перезапуск
    delay(50);                        // прошло 50 мс
    timer.tac();
    assertEqual(handler.callCount, 0);

    delay(60);                        // ещё 60 = 110 мс
    timer.tac();
    assertEqual(handler.callCount, 1);
}

test(delayTimer_multiple_in_chain) {
    handler.reset();
    DelayTimer t1, t2;
    
    t1.start(100, &handler);
    t2.start(200, &handler);
    
    delay(150);
    t1.tac();  // вызовет t1.tick(), но t2.tick() не вызовется, потому что t2 не в цепочке t1
    
    // Лучше вызвать у первого в цепочке
    // Tickable::chain()->tac();  // пройдёт по всей цепочке
    
    // Для простоты теста:
    t1.tac();
    t2.tac();  // вызываем оба явно
    
    assertEqual(handler.callCount, 1);  // t1 сработал, t2 ещё нет
    
    delay(100);  // ещё 100 = 250 всего
    t1.tac();
    t2.tac();
    assertEqual(handler.callCount, 2);  // t2 сработал
}

// -------------------------------------------------------------------
// RepeatTimer
// -------------------------------------------------------------------
test(repeatTimer_triggers_periodically) {
    handler.reset();
    RepeatTimer timer(150, &handler);

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
    RepeatTimer timer(150, &handler);

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
    RepeatTimer timer(200, &handler);

    delay(200);
    timer.tac();
    assertEqual(handler.callCount, 1);

    timer.start(100, &handler);
    handler.reset();

    delay(100);
    timer.tac();
    assertEqual(handler.callCount, 1);

    delay(100);
    timer.tac();
    assertEqual(handler.callCount, 2);
}

// -------------------------------------------------------------------
// Демонстрация работы цепочки
// -------------------------------------------------------------------
test(tac_through_chain) {
    handler.reset();
    DelayTimer t1, t2, t3;
    
    t1.start(50, &handler);
    t2.start(100, &handler);
    t3.start(150, &handler);
    
    // Получаем голову цепочки
    Tickable* head = Tickable::chain();
    assertNotEqual(head, nullptr);
    
    // Проходим 60 мс
    delay(60);
    head->tac();  // пройдёт по всем трём
    
    // Должен сработать только t1
    assertEqual(handler.callCount, 1);
    
    delay(50);  // ещё 50 = 110 всего
    head->tac();
    
    // Должен сработать t2
    assertEqual(handler.callCount, 2);
    
    delay(50);  // ещё 50 = 160 всего
    head->tac();
    
    // Должен сработать t3
    assertEqual(handler.callCount, 3);
}

