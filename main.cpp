#include <iostream>
#include "doubly_linked_list.hpp"
#include "evaluator.hpp"

int main() {
    std::cout << "Doubly Linked List Demo" << std::endl;
    std::cout << "***********************" << std::endl;
    
    DoublyLinkedList list;
    
    // Check if list is empty
    std::cout << "Is list empty? " << (list.is_empty() ? "Yes" : "No") << std::endl;
    
    std::cout << "\nAdding elements to the list" << std::endl;
    list.push_back(10);
    list.push_back(30);
    list.push_front(5);
    list.push_back(40);
    list.push_front(1);
    
    std::cout << "List contents: ";
    list.print();
    
    std::cout << "List contents (reverse): ";
    list.print_reverse();
    
    std::cout << "List size: " << list.size() << std::endl;
    
    // Access elements by index
    std::cout << "\nAccessing elements by index:" << std::endl;
    try {
        std::cout << "Element at index 0: " << list.at(0) << std::endl;
        std::cout << "Element at index 2: " << list.at(2) << std::endl;
        std::cout << "Element at index 4: " << list.at(4) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\nTesting sorting algorithms:" << std::endl;
    
    // Create lists for each sort type
    DoublyLinkedList list_merge = list;
    DoublyLinkedList list_quick = list;
    DoublyLinkedList list_insertion = list;
    
    // Merge sort
    std::cout << "Before merge sort: ";
    list_merge.print();
    list_merge.merge_sort();
    std::cout << "After merge sort: ";
    list_merge.print();
    
    // Quick sort
    std::cout << "Before quick sort: ";
    list_quick.print();
    list_quick.quick_sort();
    std::cout << "After quick sort: ";
    list_quick.print();
    
    // Insertion sort
    std::cout << "Before insertion sort: ";
    list_insertion.print();
    list_insertion.insertion_sort();
    std::cout << "After insertion sort: ";
    list_insertion.print();
    
    return 0;
}