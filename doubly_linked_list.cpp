#include <stdexcept>
#include <iostream>
#include "doubly_linked_list.hpp"

DLLNode::DLLNode() {
    next = nullptr;
    prev = nullptr;
}

DLLNode::DLLNode(int v) {
    value = v;
    next = nullptr;
    prev = nullptr;
}

DLLNode::DLLNode(DLLNode* n) {
    value = 0;
    next = n;
    prev = nullptr;
}

DLLNode::DLLNode(int v, DLLNode* n) {
    value = v;
    next = n;
    prev = nullptr;
}

DLLNode::DLLNode(int v, DLLNode* n, DLLNode* p) {
    value = v;
    next = n;
    prev = p;
}

DLLNode::~DLLNode() {
    // commented out to reduce
    // std::cout << "starting dll node destructor" << std::endl;
    // if(next != nullptr){
    //     std::cout << "deleting next" << std::endl;
    //     std::cout << "node value: " << value << std::endl;
    //     std::cout << "node next: " << next << std::endl;
    //     delete next;
    //     std::cout << "next setting to nullptr" << std::endl;
    //     next = nullptr;
    // }
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    //std::cout << "start doubly linked list deconstructor" << std::endl;
    if (head != nullptr) {
        //std::cout << "deleting head" << std::endl;
        delete head;
        //std::cout << "setting head to nullptr" << std::endl;
        head = nullptr;
    }
}

bool DoublyLinkedList::push_back(int v) {
    if (is_empty()) {
        return push_front(v);
    }
    DLLNode* new_node = new DLLNode(v);
    // new_node's prev pointer is set to the current tail
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
    return true;
}

bool DoublyLinkedList::push_front(int v) {
    DLLNode* new_node = new DLLNode(v);
    if (is_empty()) {
        head = new_node;
        tail = new_node;
    } 
    else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return true;
}

int DoublyLinkedList::at(int i) {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("invalid Index for List");
    }
    DLLNode* iter;
    if (i < size() / 2) {
        iter = head;
        for (int count = 0; count < i; count++) {
            iter = iter->next;
        }
    } 
    else {
        iter = tail;
        for (int count = size() - 1; count > i; count--) {
            iter = iter->prev;
        }
    }
    return iter->value;
}

bool DoublyLinkedList::is_empty() {
    // A tad overkill but rather safe than sorry
    return (head == nullptr && tail == nullptr);
}

int DoublyLinkedList::size() {
    if (is_empty()) {
        return 0;
    }
    int count = 1;
    for (DLLNode* iter = head; iter->next != nullptr; iter=iter->next) {
        count++;
    }
    return count;
}

void DoublyLinkedList::print() {
    DLLNode* iter = head;
    while (iter != nullptr) {
        std::cout << iter->value << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::print_reverse() {
    DLLNode* iter = tail;
    while (iter != nullptr) {
        std::cout << iter->value << " ";
        iter = iter->prev;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::merge_sort() {
    if (!head || !head->next) return; // Already sorted
    
    head = merge_sort_helper(head);
    
    // Update tail pointer
    tail = head;
    while (tail && tail->next) {
        tail = tail->next;
    }
}

// Recursive merge sort helper
DLLNode* DoublyLinkedList::merge_sort_helper(DLLNode* head) {
    if (!head || !head->next) return head;
    
    // Find middle using slow/fast pointer technique
    DLLNode* slow = head;
    DLLNode* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    DLLNode* mid = slow->next;
    slow->next = nullptr; // Split the list
    if (mid) mid->prev = nullptr;
    
    DLLNode* left = merge_sort_helper(head);
    DLLNode* right = merge_sort_helper(mid);
    
    return merge(left, right);
}

DLLNode* DoublyLinkedList::merge(DLLNode* left, DLLNode* right) {
    if (left == nullptr) {
        return right;
    }

    if (right == nullptr) {
        return left;
    }

    DLLNode* result = nullptr;

    // Choose smaller value to start with
    if (left->value <= right->value) {
        result = left;
        result->next = merge(left->next, right);
        if (result->next != nullptr) {
            result->next->prev = result;
        }
    }
    else {
        result = right;
        result->next = merge(left, right->next);
        if (result->next != nullptr) {
            result->next->prev = result;
        }
    }

    return result;
}

void DoublyLinkedList::quick_sort() {
    // Base case, empty list or single element is already sorted
    if (is_empty() || size() == 1) {
        return;
    }

    quick_sort_helper(head, tail);
}

void DoublyLinkedList::quick_sort_helper(DLLNode* start, DLLNode* end) {
    // Base case, empty list or list with one element
    if (start == nullptr || end == nullptr || start == end) {
        return;
    }

    // Use first element as pivot
    int pivot_value = start->value;
    DLLNode* i = start;

    for (DLLNode* j = start->next; j != nullptr; j = j->next) {
        if (j->value < pivot_value) {
            // Move i forward and swap values with j
            i = i->next;
            std::swap(i->value, j->value);
        }

        // Break if end is reached
        if (j == end) {
            break;
        }
    }

    // Swap pivot with element at correct position
    std::swap(start->value, i->value);

    // Sort sublists
    if (start != i) {
        quick_sort_helper(start, i->prev);
    }

    if (i != end) {
        quick_sort_helper(i->next, end);
    }
}

void DoublyLinkedList::insertion_sort() {
    // Base cases, empty list or single element that is already sorted
    if (is_empty() || size() == 1) {
        return;
    }

    // Start with second element (first is already sorted)
    DLLNode* unsorted = head->next;

    while (unsorted != nullptr) {
        // Store next unsorted element before maybe moving current
        DLLNode* next = unsorted->next;
        DLLNode* current = unsorted;

        // Find each position to insert current in sorted part
        DLLNode* iter = head;
        while (iter != current && iter->value <= current->value) {
            iter = iter->next;
        }

        // If current already in correct position, just continue
        if (iter == current) {
            unsorted = next;
            continue;
        }

        // Remove current from position
        current->prev->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }

        // Insert current before iter
        if (iter == head) {
            // Insert at beginning
            current->next = head;
            current->prev = nullptr;
            head->prev = current;
            head = current;
        }
        else {
            // Insert in middle
            current->next = iter;
            current->prev = iter->prev;
            iter->prev->next = current;
            iter->prev = current;
        }

        // Move to next unsorted element
        unsorted = next;
    }
}