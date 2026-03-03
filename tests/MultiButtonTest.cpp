// #define private public


// #include <AUnit.h>
// #include "MockReader.h"
// #include "TestHandler.h"
// #include <evaMultiButton.h>

// using namespace aunit;
// using namespace eva;

// using TestMultiButton = MultiButton<MockReader>;

// test(multibutton_detects_press_with_code) {
//     TestMultiButton btn;
//     TestHandler handler;
    
//     btn.setListener(&handler, MB_EVENTS::ON_PRESS);
    
//     // Нажимаем кнопку с кодом 3
//     btn.setValue(3);
//     btn.tick();
    
//     assertEqual(handler.callCount, 1);
//     assertEqual(handler.lastArgs, MB_EVENTS::ON_PRESS | 3);
//     assertEqual(btn.getValue(), 3);
// }

// test(multibutton_detects_release_with_code) {
//     TestMultiButton btn;
//     TestHandler handler;
    
//     btn.setListener(&handler, MB_EVENTS::ON_RELEASE);
    
//     // Сначала нажимаем кнопку 2
//     btn.setValue(2);
//     btn.tick();
//     handler.reset();
    
//     // Отпускаем
//     btn.setValue(0);
//     btn.tick();
    
//     assertEqual(handler.callCount, 1);
//     assertEqual(handler.lastArgs, MB_EVENTS::ON_RELEASE | 2);
// }

// test(multibutton_short_click_with_code) {
//     TestMultiButton btn;
//     TestHandler handler;
    
//     btn.setListener(&handler, MB_EVENTS::ON_SHORTCLICK);
    
//     // Нажимаем кнопку 4
//     btn.setValue(4);
//     btn.tick();
    
//     delay(500); // меньше 750мс
    
//     // Отпускаем
//     btn.setValue(0);
//     btn.tick();
    
//     assertEqual(handler.callCount, 1);
//     assertEqual(handler.lastArgs, MB_EVENTS::ON_SHORTCLICK | 4);
// }

// test(multibutton_long_click_with_code) {
//     TestMultiButton btn;
//     TestHandler handler;
    
//     btn.setListener(&handler, MB_EVENTS::ON_LONGCLICK);
    
//     // Нажимаем кнопку 1
//     btn.setValue(1);
//     btn.tick();
    
//     delay(800); // больше 750мс
    
//     // Держим
//     btn.tick();
    
//     assertEqual(handler.callCount, 1);
//     assertEqual(handler.lastArgs, MB_EVENTS::ON_LONGCLICK | 1);
// }

// test(multibutton_switch_directly) {
//     TestMultiButton btn;
//     TestHandler handler;
    
//     btn.setListener(&handler, MB_EVENTS::ON_PRESS | MB_EVENTS::ON_RELEASE);
    
//     // Нажимаем кнопку 1
//     btn.setValue(1);
//     btn.tick();
//     assertEqual(handler.callCount, 1);
//     assertEqual(handler.lastArgs, MB_EVENTS::ON_PRESS | 1);
    
//     handler.reset();
    
//     // Прямое переключение на кнопку 2
//     btn.setValue(2);
//     btn.tick();
    
//     // Должны получить RELEASE для 1 и PRESS для 2
//     // Порядок может быть разным, проверяем что было 2 события
//     assertEqual(handler.callCount, 2);
// }

// test(multibutton_zero_is_no_button) {
//     TestMultiButton btn;
//     TestHandler handler;
    
//     btn.setListener(&handler, MB_EVENTS::ON_PRESS);
    
//     btn.setValue(0);
//     btn.tick();
    
//     assertEqual(handler.callCount, 0);
//     assertEqual(btn.getValue(), 0);
// }

// test(multibutton_multiple_buttons) {
//     TestMultiButton btn;
//     TestHandler handler;
    
//     btn.setListener(&handler, MB_EVENTS::ON_PRESS);
    
//     // Проверяем разные коды
//     for(int code = 1; code <= 5; code++) {
//         btn.setValue(code);
//         btn.tick();
        
//         assertEqual(handler.lastArgs, MB_EVENTS::ON_PRESS | code);
//         assertEqual(btn.getValue(), code);
        
//         handler.reset();
//         btn.setValue(0);
//         btn.tick(); // отпускаем
//     }
// }

// test(multibutton_can_be_disabled) {
//     TestMultiButton btn;
//     TestHandler handler;
    
//     btn.setListener(&handler, MB_EVENTS::ON_PRESS);
//     btn.enable(false);
    
//     btn.setValue(3);
//     btn.tick();
    
//     assertEqual(handler.callCount, 0);
//     assertEqual(btn.getValue(), 0);
// }