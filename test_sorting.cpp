#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include "doubly_linked_list.hpp"
#include <vector>
#include <algorithm>
#include "vector_sorter.hpp"

// Doubly Linked List Tests

// Add elements to an empty list and then add to a non-empty list
bool DLL_test_push_back() {
    // Setup
    DoublyLinkedList list;

    // Execution
    bool result1 = list.push_back(100);
    bool result2 = list.push_back(80);
    bool result3 = list.push_back(60);

    // Validation
    assert(result1);
    assert(result2);
    assert(result3);
    DLLNode* head = list.get_head();
    assert(head->value == 100);
    assert(head->next->value == 80);
    assert(head->next->next->value == 60);
    assert(head->next->next->next == nullptr);

    // Clean up
    return true;
}

bool DLL_test_push_front() {
    // Setup
    DoublyLinkedList list;

    // Execution
    bool result1 = list.push_front(5);
    bool result2 = list.push_front(15);

    // Validation
    assert(result1);
    assert(result2);
    DLLNode* head = list.get_head();
    // Expect most recent push_front value, 15, at head
    assert(head->value == 15);
    assert(head->next->value == 5);
    assert(head->next->next == nullptr);

    // Clean up
    return true;
}

// Retrieve values by index and ensure errors are thrown for invalid indices
bool DLL_test_at() {
    // Setup
    DoublyLinkedList list;
    list.push_front(11);
    list.push_front(22);
    list.push_front(33);
    
    // Execution
    int val0, val1, val2;
    try {
        val0 = list.at(0);
        val1 = list.at(1);
        val2 = list.at(2);
    } catch(...) {
        return false;
    }
    int invalidNeg = 1, invalidLarge = 1;
    try {
        list.at(-5);
    } catch (std::out_of_range&) {
        invalidNeg = 0;
    }
    try {
        list.at(100);
    } catch (std::out_of_range&) {
        invalidLarge = 0;
    }
    
    // Validation
    assert(val0 == 33);
    assert(val1 == 22);
    assert(val2 == 11);
    assert(invalidNeg == 0);
    assert(invalidLarge == 0);
    
    // Cleanup
    return true;
}

// Check behavior on an empty list and a non-empty list
bool DLL_test_is_empty() {
    // Setup
    DoublyLinkedList list1, list2;
    list2.push_front(7);

    // Execution
    bool empty1 = list1.is_empty();
    bool empty2 = list2.is_empty();

    // Validation
    assert(empty1);
    assert(!empty2);

    // Clean up
    return true;
}

// Ensure that the reported size matches the number of elements
bool DLL_test_size() {
    // Setup
    DoublyLinkedList list1, list2, list3;
    list2.push_front(9);
    list3.push_front(3);
    list3.push_front(6);

    // Execution
    int size1 = list1.size();
    int size2 = list2.size();
    int size3 = list3.size();

    // Validation
    assert(size1 == 0);
    assert(size2 == 1);
    assert(size3 == 2);

    // Clean up
    return true;
}

// Recuresively divides the list into halves, sorts each half, and merges them to produce a fully sorted list
bool DLL_test_merge_sort() {
    // Setup
    DoublyLinkedList empty_list, single_element, unsorted_list;

    single_element.push_back(42);

    unsorted_list.push_back(30);
    unsorted_list.push_back(10);
    unsorted_list.push_back(50);
    unsorted_list.push_back(20);
    unsorted_list.push_back(40);
    unsorted_list.push_back(60);

    // Execution
    empty_list.merge_sort();
    single_element.merge_sort();
    unsorted_list.merge_sort();

    // Validation
    assert(empty_list.is_empty());

    assert(single_element.size() == 1);
    assert(single_element.at(0) == 42);

    assert(unsorted_list.at(0) == 10);
    assert(unsorted_list.at(1) == 20);
    assert(unsorted_list.at(2) == 30);
    assert(unsorted_list.at(3) == 40);
    assert(unsorted_list.at(4) == 50);
    assert(unsorted_list.at(5) == 60);

    // Clean up
    return true;
}

// Validates that merging two ordered lists results in a combined list that maintains sorted order
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
    DLLNode* result2 = non_empty_list.merge(non_empty_list.get_head(), empty_list.get_head());
    assert(result2 != nullptr);
    assert(result2->value == 5);

    // Clean up 
    return true;
    
}

// Selects a pivot (the first element in our case), partitions the list around the pivot, and recursively sorts the partitions
bool DLL_test_quick_sort() {
    // Setup
    DoublyLinkedList empty_list, single_element, unsorted_list;

    single_element.push_back(42);

    unsorted_list.push_back(30);
    unsorted_list.push_back(10);
    unsorted_list.push_back(50);
    unsorted_list.push_back(20);
    unsorted_list.push_back(40);
    unsorted_list.push_back(60);

    // Execution
    empty_list.quick_sort();
    single_element.quick_sort();
    unsorted_list.quick_sort();

    // Validation
    assert(empty_list.is_empty());

    assert(single_element.size() == 1);
    assert(single_element.at(0) == 42);

    assert(unsorted_list.at(0) == 10);
    assert(unsorted_list.at(1) == 20);
    assert(unsorted_list.at(2) == 30);
    assert(unsorted_list.at(3) == 40);
    assert(unsorted_list.at(4) == 50);
    assert(unsorted_list.at(5) == 60);

    // Clean up
    return true;
}

// Builds the sorted list one element at a time by inserting elements into a sublist of already sorted elements
bool DLL_test_insertion_sort() {
    // Setup
    DoublyLinkedList empty_list, single_element, unsorted_list;

    single_element.push_back(42);

    unsorted_list.push_back(30);
    unsorted_list.push_back(10);
    unsorted_list.push_back(50);
    unsorted_list.push_back(20);
    unsorted_list.push_back(40);
    unsorted_list.push_back(60);

    // Execution
    empty_list.insertion_sort();
    single_element.insertion_sort();
    unsorted_list.insertion_sort();

    // Validation
    assert(empty_list.is_empty());

    assert(single_element.size() == 1);
    assert(single_element.at(0) == 42);

    assert(unsorted_list.at(0) == 10);
    assert(unsorted_list.at(1) == 20);
    assert(unsorted_list.at(2) == 30);
    assert(unsorted_list.at(3) == 40);
    assert(unsorted_list.at(4) == 50);
    assert(unsorted_list.at(5) == 60);

    // Clean up
    return true;
}

// Vector Sorter Tests

bool vector_test_merge_sort() {
    // test for an empty vector, a length of one, and a length of many nums
    // set up
    VectorSorter sorter; // make an instance of the object
    std::vector<int> empty; 
    std::vector<int> single = {5};
    std::vector<int> nums = {3, 6, 2, 1, 4};

    // execution
    sorter.merge_sort(empty); // call a sort on the empty vector
    sorter.merge_sort(single); // call a sort of the one-value vector
    sorter.merge_sort(nums); // call a sort on the vector of numbers

    // validation
    assert(empty.empty()); // assert that empty is still empty
    assert(single.size() == 1 && single[0] == 5); // assert that the single value vector is still five and length of one
    assert(std::is_sorted(nums.begin(), nums.end())); // assert that nums is sorted in ascending order

    // clean up
    return true;
}

bool vector_test_merge() {
    // test for merging two sorted subarrays, already sorted arrays, single element arrays, empty merges and for unequal size merging
    // set up: 
    VectorSorter sorter;
    std::vector<int> nums = {1, 4, 9, 2, 3, 6};

    // execution: 
    sorter.merge(nums, 0, 2, 5); // merging [1, 4, 9] and [2, 3, 6]

    // validation:
    assert(nums == std::vector<int>({1, 2, 3, 4, 6, 9}));

    nums = {1, 2, 3, 4, 5, 6}; // another set up 
    sorter.merge(nums, 0, 2, 5); // no changing, another execution
    assert(nums == std::vector<int>({1, 2, 3, 4, 5, 6})); // another validation

    nums = {5, 1}; // another set up
    sorter.merge(nums, 0, 0, 1); // merging [5] and [1], another execution
    assert(nums == std::vector<int>({1, 5})); // another validation 

    nums = {}; // another set up
    sorter.merge(nums, 0, 0, 0); // another execution that doesnt actually execute fully lol because its empty
    assert(nums.empty()); // another validation

    nums = {1, 10, 2, 5, 8}; // another set up
    sorter.merge(nums, 0, 1, 4); // merging [1, 10] and [2, 5, 8], another execution
    assert(nums == std::vector<int>({1, 2, 5, 8, 10})); // another validation

    // clean up
    return true;
}

bool vector_test_quick_sort() {
    // test for an empty vector, a length of one, and a length of many nums
    // set up
    VectorSorter sorter;
    std::vector<int> empty;
    std::vector<int> single = {7};
    std::vector<int> nums = {9, 3, 2, 5, 6};

    // execution
    sorter.quick_sort(empty);
    sorter.quick_sort(single);
    sorter.quick_sort(nums);

    // validation
    assert(empty.empty());
    assert(single.size() == 1 && single[0] == 7);
    assert(std::is_sorted(nums.begin(), nums.end()));

    // clean up
    return true;
}

bool vector_test_insertion_sort() {
    // test for an empty vector, a length of one, and a length of many nums
    // set up
    VectorSorter sorter;
    std::vector<int> empty;
    std::vector<int> single = {2};
    std::vector<int> nums = {8, 4, 1, 2, 5};

    // execution
    sorter.insertion_sort(empty);
    sorter.insertion_sort(single);
    sorter.insertion_sort(nums);

    // validation
    assert(empty.empty());
    assert(single.size() == 1 && single[0] == 2);
    assert(std::is_sorted(nums.begin(), nums.end()));

    // clean up
    return true;
}

int main() {
    std::cout << "Starting Doubly Linked List Tests" << std::endl;
    
    std::cout << "Push back: "
              << (DLL_test_push_back() ? "Passed" : "Failed") << std::endl;
    std::cout << "Push front: "
              << (DLL_test_push_front() ? "Passed" : "Failed") << std::endl;
    std::cout << "At: "
              << (DLL_test_at() ? "Passed" : "Failed") << std::endl;
    std::cout << "Is empty: "
              << (DLL_test_is_empty() ? "Passed" : "Failed") << std::endl;
    std::cout << "Size: "
              << (DLL_test_size() ? "Passed" : "Failed") << std::endl;
    std::cout << "Merge Sort: " 
              << (DLL_test_merge_sort() ? "Passed" : "Failed") << std::endl;
    std::cout << "Merge: " 
              << (DLL_test_merge() ? "Passed" : "Failed") << std::endl;
    std::cout << "Quick Sort: " 
              << (DLL_test_quick_sort() ? "Passed" : "Failed") << std::endl;
    std::cout << "Insertion Sort: " 
              << (DLL_test_insertion_sort() ? "Passed" : "Failed") << std::endl;

    std::cout << "\nStarting Vector Sorter Tests" << std::endl;
    std::cout << "Vector Merge sort: " 
              << (vector_test_merge_sort() ? "Passed" : "Failed") << std::endl;
    std::cout << "Merge function: " << (vector_test_merge() ? "Passed" : "Failed") << std::endl;
    std::cout << "Vector Quick sort: " 
              << (vector_test_quick_sort() ? "Passed" : "Failed") << std::endl;
    std::cout << "Vector Insertion sort: " 
              << (vector_test_insertion_sort() ? "Passed" : "Failed") << std::endl;
    return 0;
}