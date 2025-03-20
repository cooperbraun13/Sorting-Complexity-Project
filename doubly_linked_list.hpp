#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class DLLNode {
    public:
        int value;
        DLLNode* next;
        DLLNode* prev;
        DLLNode();
        DLLNode(int v);
        DLLNode(DLLNode* n);
        DLLNode(int v, DLLNode* n);
        DLLNode(int v, DLLNode* n, DLLNode* p);
        ~DLLNode();
};

class DoublyLinkedList {
    private:
        DLLNode* head;
        DLLNode* tail;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        bool push_back(int v);
        bool push_front(int v);
        int at(int i);
        bool is_empty();
        int size();
        void print();
        void print_reverse();
        DLLNode* get_head() { return head; }
        DLLNode* get_tail() { return tail; }
};

#endif