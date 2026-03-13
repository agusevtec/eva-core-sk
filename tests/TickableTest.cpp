#include <AUnit.h>
#include <evaTickable.h>

using namespace aunit;
using namespace eva;

class TestTickable : public Tickable {
public:
    int tickCount = 0;
    
protected:
    void tick() override {
        tickCount++;
    }
};

class TrackedTickable : public Tickable {
public:
    int id;
    static int destructionCount;
    
    TrackedTickable(int _id) : id(_id) {}
    
    ~TrackedTickable() {
        destructionCount++;
    }
    
protected:
    void tick() override {
        return ;
    }
};

int TrackedTickable::destructionCount = 0;

test(tickable_tac_calls_tick_on_all_in_chain) {
    TestTickable t1;
    TestTickable t2;
    TestTickable t3;
    
    t1.tickCount = 0;
    t2.tickCount = 0;
    t3.tickCount = 0;
    
    t1.tac();
    
    assertEqual(t1.tickCount, 1);
    assertEqual(t2.tickCount, 1);
    assertEqual(t3.tickCount, 1);
}

test(tickable_destructor_removes_from_chain) {
    TestTickable* t1 = new TestTickable();
    TestTickable* t2 = new TestTickable();
    TestTickable* t3 = new TestTickable();
    
    t1->tac();
    assertEqual(t1->tickCount, 1);
    assertEqual(t2->tickCount, 1);
    assertEqual(t3->tickCount, 1);
    
    t1->tickCount = 0;
    t2->tickCount = 0;
    t3->tickCount = 0;
    
    delete t2;
    
    t1->tac();
    assertEqual(t1->tickCount, 1);
    assertEqual(t3->tickCount, 1);
}

test(tickable_destructor_removes_first_from_chain) {
    TestTickable* t1 = new TestTickable();
    TestTickable* t2 = new TestTickable();
    TestTickable* t3 = new TestTickable();
    
    delete t1;
    
    t2->tac();
    assertEqual(t2->tickCount, 1);
    assertEqual(t3->tickCount, 1);
}

test(tickable_destructor_removes_last_from_chain) {
    TestTickable* t1 = new TestTickable();
    TestTickable* t2 = new TestTickable();
    TestTickable* t3 = new TestTickable();
    
    delete t3;
    
    t1->tac();
    assertEqual(t1->tickCount, 1);
    assertEqual(t2->tickCount, 1);
    
    delete t2;
}

test(tickable_destructor_chain_integrity) {
    TrackedTickable::destructionCount = 0;
    
    {
        TrackedTickable t1(1);
        TrackedTickable t2(2);
        TrackedTickable t3(3);
        
    }
    
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
    
    TestTickable t3;
    
    t3.tac();
    assertEqual(t3.tickCount, 1);
}

