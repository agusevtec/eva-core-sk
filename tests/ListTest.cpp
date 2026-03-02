#line 2 "ListTest.cpp"

#include <AUnit.h>
#include <evaList.h>

using namespace aunit;
using namespace eva;

test(list_can_be_created) {
    List<int> list;
    assertEqual(list.count(), 0u);
}

test(list_can_add_one_item) {
    List<int> list;
    list.append(42);
    
    assertEqual(list.count(), 1u);
    assertEqual(list[0], 42);
}

test(list_can_add_multiple_items) {
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    assertEqual(list.count(), 3u);
    assertEqual(list[0], 10);
    assertEqual(list[1], 20);
    assertEqual(list[2], 30);
}

test(list_can_iterate) {
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    int sum = 0;
    for (auto* iter = list.first(); iter != nullptr; iter = iter->next) {
        sum += iter->item;
    }
    
    assertEqual(sum, 6);
}

test(list_works_with_strings) {
    List<const char*> list;
    list.append("hello");
    list.append("world");
    
    assertEqual(list.count(), 2u);
    assertEqual(list[0], "hello");
    assertEqual(list[1], "world");
}

test(list_handles_empty) {
    List<int> list;
    assertEqual(list.first(), nullptr);
    assertEqual(list.count(), 0u);
}