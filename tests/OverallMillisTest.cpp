#include <AUnit.h>
using namespace aunit;

#define private public
#define protected public

#include <evaDelayTimer.h>
#include <evaButton.h>
using namespace eva;

#include "TestHandler.h"
#include "MockReader.h"

class MockMillis {
private:
    static unsigned long currentTime;
public:
    static unsigned long millis() { return currentTime; }
    static void set(unsigned long t) { currentTime = t; }
    static void step(unsigned long delta) { currentTime += delta; }
};
unsigned long MockMillis::currentTime = 0;

using TestButton = Button<MockReader>;

#undef millis
#define millis() MockMillis::millis()

test(delayTimer_handles_overflow) {
    TestHandler handler;
    
    // Устанавливаем время почти в конце
    MockMillis::set(0xFFFFFFF0);
    
    DelayTimer timer;

    timer.start(200, &handler); // nextFire = 0xFFFFFFF0 + 200 = 0xFFFFFEC8 (переполнение!)
    assertLess(timer.nextFire, 0xFFF);

    // Проверяем что не сработал сразу
    timer.tick();
    assertEqual(handler.callCount, 0);
    
    // Переполняем millis
    MockMillis::set(100); // millis = 100, nextFire = 0xFFFFFEC8 (> 100)
    
    // Должен сработать
    timer.tick();
    assertEqual(handler.callCount, 1);
}

test(button_pressTime_handles_overflow) {
    TestButton btn;
    TestHandler handler;
    btn.setListener(&handler, B_EVENTS::ON_LONGCLICK);
    
    // Нажимаем кнопку
    MockMillis::set(0xFFFFFF00);
    btn.setValue(1);
    btn.tick();
    
    // Проходит 800 мс с переполнением
    MockMillis::set(100); // 0xFFFFFF00 + 800 = 0xFFFFFEC8? 
    // Но millis показывает 100
    
    btn.tick(); // Должен определить LONGCLICK
    assertEqual(handler.callCount, 1); // Безопасно!
}

test(stabilizeDecor_handles_overflow) {
    StabilizeDecor<MockReader> reader;
    
    MockMillis::set(0xFFFFFF00);
    reader.setValue(100);
    reader.getValue(); // запоминает
    
    reader.value = 200;
    
    // Проходит 100 мс
    MockMillis::set(0xFFFFFF64);
    assertEqual(reader.getValue(), 100); // еще стабилизирует
    
    // Переполнение
    MockMillis::set(100);
    
    // Должен вернуть новое значение
    assertEqual(reader.getValue(), 200);
}