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

    // Сначала нажимаем
    btn.setValue(1);
    btn.tac();
    handler.reset();

    // Ждем немного
    delay(100);

    // Отпускаем
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

    // Нажимаем
    btn.setValue(1);
    btn.tac();

    // Ждем немного (меньше 750мс)
    delay(500);

    // Отпускаем
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

    // Нажимаем
    btn.setValue(1);
    btn.tac();

    // Ждем больше 750мс
    delay(800);

    // Держим - должен сработать LONGCLICK
    btn.tac();

    assertEqual(handler.callCount, 1);
    assertEqual((int)handler.lastEventType, (int)ON_LONGCLICK);
}

test(button_no_short_click_after_long)
{
    TestButton btn;
    MockHandler handler;

    btn.setListener(&handler, ON_SHORTCLICK | ON_LONGCLICK);

    // Нажимаем
    btn.setValue(1);
    btn.tac();
    handler.reset();

    // Ждем больше 750мс
    delay(800);
    btn.tac(); // Должен быть LONGCLICK
    assertEqual((int)handler.lastEventType, (int)ON_LONGCLICK);

    handler.reset();

    // Отпускаем - не должно быть SHORTCLICK
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
