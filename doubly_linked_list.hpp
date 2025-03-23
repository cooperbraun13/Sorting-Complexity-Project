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
        DLLNode* merge_sort_helper(DLLNode* head);
        void quick_sort_helper(DLLNode* start, DLLNode* end);
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
        DLLNode* merge(DLLNode* left, DLLNode* right);
        void merge_sort();
        void quick_sort();
        void insertion_sort();
        DLLNode* get_head() { return head; }
        DLLNode* get_tail() { return tail; }
};

#endif