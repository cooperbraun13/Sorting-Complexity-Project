#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include "doubly_linked_list.hpp"

bool DLL_test_merge_sort() {
    // Setup

    // Execution

    // Validation

    // Clean up
}

bool DLL_test_merge() {
    // Setup
    DoublyLinkedList list1, list2;

    list1.push_back(10);
    list1.push_back(30);
    list1.push_back(50);

    list2.push_back(20);
    list2.push_back(40);
    list2.push_back(60);

    // Execution
    DLLNode* merged_head = list1.merge(list1.get_head(), list2.get_head());

    // Validation
    assert(merged_head != nullptr);
    assert(merged_head->value == 10);

    assert(merged_head->next != nullptr);
    assert(merged_head->next->value == 20);

    assert(merged_head->next->next != nullptr);
    assert(merged_head->next->next->value == 30);

    assert(merged_head->next->next->next != nullptr);
    assert(merged_head->next->next->next->value == 40);

    assert(merged_head->next->next->next->next != nullptr);
    assert(merged_head->next->next->next->next->value == 50);

    assert(merged_head->next->next->next->next->next != nullptr);
    assert(merged_head->next->next->next->next->next->value == 60);

    // Empty list cases
    DoublyLinkedList empty_list, non_empty_list;
    non_empty_list.push_back(5);

    // Empty and non-empty
    DLLNode* result1 = empty_list.merge(empty_list.get_head(), non_empty_list.get_head());
    assert(result1 != nullptr);
    assert(result1->value == 5);

    // Non-empty and empty
    DLLNode* result2 = non_empty_list.merge(non_empty_list.get_head(), empty_list.get_head())
    assert(result2 != nullptr);
    assert(result2->value == 5);

    // Clean up 
    return true;
    
}

bool DLL_test_quick_sort() {
    // Setup

    // Execution

    // Validation

    // Clean up
}

bool DLL_test_insertion_sort() {
    // Setup

    // Execution

    // Validation

    // Clean up
}