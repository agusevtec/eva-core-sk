#include <AUnit.h>
#include <evaList.h>

using namespace aunit;
using namespace eva;


test(list_can_be_created_empty) {
    List<int> list;
    
    assertEqual(list.count(), 0u);
    assertTrue(list.isEmpty());
    assertEqual(list.first(), nullptr);
}

test(list_can_append_single_item) {
    List<int> list;
    list.append(42);
    
    assertEqual(list.count(), 1u);
    assertFalse(list.isEmpty());
    assertNotEqual(list.first(), nullptr);
    assertEqual(*list[0], 42);
}

test(list_can_append_multiple_items) {
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    assertEqual(list.count(), 3u);
    assertEqual(*list[0], 10);
    assertEqual(*list[1], 20);
    assertEqual(*list[2], 30);
}


test(list_operator_returns_nullptr_for_out_of_bounds) {
    List<int> list;
    list.append(42);
    
    assertEqual(list[0] != nullptr, true);
    assertEqual(list[1], nullptr);
    assertEqual(list[99], nullptr);
}

test(list_operator_works_with_various_indices) {
    List<int> list;
    for (int i = 0; i < 10; i++) {
        list.append(i * 10);
    }
    
    for (int i = 0; i < 10; i++) {
        assertEqual(*list[i], i * 10);
    }
}


test(list_can_be_traversed_via_iterator) {
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    int sum = 0;
    int count = 0;
    for (auto* iter = list.first(); iter != nullptr; iter = iter->next) {
        sum += iter->item;
        count++;
    }
    
    assertEqual(sum, 6);
    assertEqual(count, 3);
}

test(list_iterator_works_with_empty_list) {
    List<int> list;
    
    int count = 0;
    for (auto* iter = list.first(); iter != nullptr; iter = iter->next) {
        count++;
    }
    
    assertEqual(count, 0);
}


test(list_can_remove_item_by_value) {
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(20);
    
    bool removed = list.remove(20);  
    
    assertTrue(removed);
    assertEqual(list.count(), 3u);
    assertEqual(*list[0], 10);
    assertEqual(*list[1], 30);  
    assertEqual(*list[2], 20);
}

test(list_remove_returns_false_for_nonexistent_item) {
    List<int> list;
    list.append(10);
    list.append(20);
    
    bool removed = list.remove(99);
    
    assertFalse(removed);
    assertEqual(list.count(), 2u);
}

test(list_can_remove_item_at_index) {
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    
    bool removed = list.removeAt(1);  
    
    assertTrue(removed);
    assertEqual(list.count(), 3u);
    assertEqual(*list[0], 10);
    assertEqual(*list[1], 30);
    assertEqual(*list[2], 40);
}

test(list_removeAt_returns_false_for_invalid_index) {
    List<int> list;
    list.append(10);
    
    assertFalse(list.removeAt(1));  
    assertFalse(list.removeAt(5));  
    assertEqual(list.count(), 1u);
}

test(list_can_remove_first_element) {
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    bool removed = list.removeAt(0);
    
    assertTrue(removed);
    assertEqual(list.count(), 2u);
    assertEqual(*list[0], 20);
    assertEqual(*list[1], 30);
}

test(list_can_remove_last_element) {
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    bool removed = list.removeAt(2);
    
    assertTrue(removed);
    assertEqual(list.count(), 2u);
    assertEqual(*list[0], 10);
    assertEqual(*list[1], 20);
}

// Поиск
test(list_can_find_index_of_item) {
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(20);
    
    assertEqual(list.indexOf(10), 0);
    assertEqual(list.indexOf(20), 1);  
    assertEqual(list.indexOf(30), 2);
    assertEqual(list.indexOf(99), -1);  
}

test(list_indexOf_works_with_empty_list) {
    List<int> list;
    assertEqual(list.indexOf(42), -1);
}


test(list_can_be_cleared) {
    List<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    assertEqual(list.count(), 3u);
    
    list.clear();
    
    assertEqual(list.count(), 0u);
    assertTrue(list.isEmpty());
    assertEqual(list.first(), nullptr);
    assertEqual(list[0], nullptr);
}


test(list_can_be_copy_constructed) {
    List<int> original;
    original.append(1);
    original.append(2);
    original.append(3);
    
    List<int> copy(original);
    
    assertEqual(copy.count(), 3u);
    assertEqual(*copy[0], 1);
    assertEqual(*copy[1], 2);
    assertEqual(*copy[2], 3);
    
    
    copy.removeAt(0);
    assertEqual(copy.count(), 2u);
    assertEqual(original.count(), 3u);
}

test(list_can_be_assigned) {
    List<int> original;
    original.append(1);
    original.append(2);
    
    List<int> assigned;
    assigned = original;
    
    assertEqual(assigned.count(), 2u);
    assertEqual(*assigned[0], 1);
    assertEqual(*assigned[1], 2);
}

test(list_assignment_handles_self_assignment) {
    List<int> list;
    list.append(42);
    
    list = list; 
    
    assertEqual(list.count(), 1u);
    assertEqual(*list[0], 42);
}

test(list_works_with_strings) {
    List<const char*> list;
    list.append("hello");
    list.append("world");
    
    assertEqual(list.count(), 2u);
    assertEqual(*list[0], "hello");
    assertEqual(*list[1], "world");
}

test(list_works_with_custom_structs) {
    struct Point { int x; int y; };
    
    List<Point> list;
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    
    list.append(p1);
    list.append(p2);
    
    assertEqual(list.count(), 2u);
    assertEqual((*list[0]).x, 1);
    assertEqual((*list[0]).y, 2);
    assertEqual((*list[1]).x, 3);
    assertEqual((*list[1]).y, 4);
}