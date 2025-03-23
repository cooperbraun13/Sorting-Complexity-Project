#include <stdexcept>
#include <iostream>
#include "doubly_linked_list.hpp"

DLLNode::DLLNode() {
    value = 0;
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
    delete next;
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    delete head;
}

bool DoublyLinkedList::push_back(int v) {
    if (is_empty()) {
        return push_front(v);
    }
    DLLNode* new_node = new DLLNode(v);
    // new_node's prev pointer is set to the current tail
    new_node->prev = tail;
    tail->next = new_node;
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
    // Base cases, empty list or single element already sorted
    if (is_empty() || size() == 1) {
        return;
    }

    head = merge_sort_helper(head);

    // Update tail pointer after sorting
    DLLNode* iter = head;
    while (iter->next != nullptr) {
        iter = iter->next;
    }
    tail = iter;
}

// Recursive merge sort helper
DLLNode* DoublyLinkedList::merge_sort_helper(DLLNode* head) {
    // Base case, empty list or single element
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Count total number of nodes in list to find middle
    int count = 0;
    DLLNode* iter = head;
    while (head != nullptr) {
        count++;
        iter = iter->next;
    }

    // Find middle node
    int middle = count / 2;
    iter = head;
    for (int i = 0; i < middle; i++) {
        iter = iter->next;
    }

    // Split list into two halves
    DLLNode* right = iter->next;
    iter->next = nullptr;
    if (right != nullptr) {
        right->prev = nullptr;
    }

    DLLNode* left_sorted = merge_sort_helper(head);
    DLLNode* right_sorted = merge_sort_helper(right);

    return merge(left_sorted, right_sorted);
}

DLLNode* DoublyLinkedList::merge(DLLNode* left, DLLNode* right) {
    if (left == nullptr) {
        return right;
    }
    
    if (right == nullptr) {
        return left;
    }

    // Choose smaller value to start with
    DLLNode* result;
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

}