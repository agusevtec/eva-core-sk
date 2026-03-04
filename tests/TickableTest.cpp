// TickableTest.cpp
#include <AUnit.h>
#include <evaTickable.h>

using namespace aunit;
using namespace eva;

// Тестовый класс, наследующий Tickable
class TestTickable : public Tickable {
public:
    int tickCount = 0;
    
protected:
    short tick() override {
        tickCount++;
        return 0;
    }
};

// Для проверки удаления из середины
class TrackedTickable : public Tickable {
public:
    int id;
    static int destructionCount;
    
    TrackedTickable(int _id) : id(_id) {}
    
    ~TrackedTickable() {
        destructionCount++;
    }
    
protected:
    short tick() override {
        return 0;
    }
};

int TrackedTickable::destructionCount = 0;

test(tickable_constructor_adds_to_chain) {
    // Сбрасываем состояние (в реальности нужно иметь доступ к private static)
    TestTickable t1;
    TestTickable t2;
    TestTickable t3;
    
    // Проверяем, что цепочка не пустая
    assertNotEqual(Tickable::chain(), nullptr);
}

test(tickable_tac_calls_tick_on_all_in_chain) {
    TestTickable t1;
    TestTickable t2;
    TestTickable t3;
    
    // Сбрасываем счетчики
    t1.tickCount = 0;
    t2.tickCount = 0;
    t3.tickCount = 0;
    
    // Вызываем tac на первом - должен пройти по всей цепочке
    t1.tac();
    
    assertEqual(t1.tickCount, 1);
    assertEqual(t2.tickCount, 1);
    assertEqual(t3.tickCount, 1);
}

test(tickable_destructor_removes_from_chain) {
    TestTickable* t1 = new TestTickable();
    TestTickable* t2 = new TestTickable();
    TestTickable* t3 = new TestTickable();
    
    // Проверяем что все в цепочке
    t1->tac();
    assertEqual(t1->tickCount, 1);
    assertEqual(t2->tickCount, 1);
    assertEqual(t3->tickCount, 1);
    
    // Сбрасываем счетчики
    t1->tickCount = 0;
    t2->tickCount = 0;
    t3->tickCount = 0;
    
    // Удаляем средний элемент
    delete t2;
    
    // Tac на первом должен дойти только до t3
    t1->tac();
    assertEqual(t1->tickCount, 1);
    assertEqual(t3->tickCount, 1);
    // Не можем проверить t2 - он удален
}

test(tickable_destructor_removes_first_from_chain) {
    TestTickable* t1 = new TestTickable();
    TestTickable* t2 = new TestTickable();
    TestTickable* t3 = new TestTickable();
    
    // Удаляем первый элемент
    delete t1;
    
    // Tac на t2 должен дойти до t3
    t2->tac();
    assertEqual(t2->tickCount, 1);
    assertEqual(t3->tickCount, 1);
}

test(tickable_destructor_removes_last_from_chain) {
    TestTickable* t1 = new TestTickable();
    TestTickable* t2 = new TestTickable();
    TestTickable* t3 = new TestTickable();
    
    // Удаляем последний элемент
    delete t3;
    
    // Tac на t1 должен дойти до t2 и остановиться
    t1->tac();
    assertEqual(t1->tickCount, 1);
    assertEqual(t2->tickCount, 1);
    
    // Проверяем что t2->next теперь nullptr (через поведение, не напрямую)
    // Удаляем t2
    delete t2;
}

test(tickable_destructor_chain_integrity) {
    TrackedTickable::destructionCount = 0;
    
    {
        TrackedTickable t1(1);
        TrackedTickable t2(2);
        TrackedTickable t3(3);
        
        // Внутри блока все живы
    } // Здесь вызываются деструкторы в обратном порядке
    
    // Проверяем что все деструкторы вызвались без ошибок
    assertEqual(TrackedTickable::destructionCount, 3);
}

test(tickable_isolated_object_works) {
    TestTickable t;
    
    t.tac();
    assertEqual(t.tickCount, 1);
    
    t.tac();
    assertEqual(t.tickCount, 2);
}

test(tickable_empty_chain_after_all_deleted) {
    TestTickable* t1 = new TestTickable();
    TestTickable* t2 = new TestTickable();
    
    delete t1;
    delete t2;
    
    // Цепочка должна быть пуста
    // Не можем проверить напрямую, но можем создать новый объект
    TestTickable t3;
    
    // Должно работать без ошибок
    t3.tac();
    assertEqual(t3.tickCount, 1);
}

test(tickable_chain_persistence) {
    TestTickable* t1 = new TestTickable();
    TestTickable* t2 = new TestTickable();
    
    Tickable* head = Tickable::chain();
    assertNotEqual(head, nullptr);
    
    delete t1;
    delete t2;
    
    // После удаления head должен измениться
    // Не можем проверить напрямую, просто проверяем что новый объект работает
    TestTickable t3;
    t3.tac();
    assertEqual(t3.tickCount, 1);
}