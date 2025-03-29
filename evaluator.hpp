#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP
#include <vector>
#include <fstream>
#include "doubly_linked_list.hpp"

class Evaluator {
    public:
        std::vector <std::vector<int>> eval_vec_vec;
        std::vector <DoublyLinkedList*> eval_dll_vec;
        std::ifstream eval_file;
        std::vector<double> dll_merge_times;
        std::vector<double> dll_quick_times;
        std::vector<double> dll_insert_times;
        std::vector<double> vec_merge_times;
        std::vector<double> vec_quick_times;
        std::vector<double> vec_insert_times;
        Evaluator();
        ~Evaluator(); 
        void ingest();
        void merge_compare(); 
        void quick_compare(); 
        void insert_compare(); 
        void evaluate(); 
};

//ingest() // delimits on whitespace take in a number delimit, for four lines then update. 
// fill vector with numbers in list, same with doubly linked lists
// variables vector of doubly linked lists and vector and one for the time that it takes from 
//chrono library convert into something more readable
#endif