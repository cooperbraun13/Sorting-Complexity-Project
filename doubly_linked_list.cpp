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
    // a tad overkill but rather safe than sorry
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