#include <iostream>
#include <fstream>
#include "evaluator.hpp"
#include <string>
#include <chrono>
#include <iomanip>
#include "vector_sorter.hpp"

Evaluator::Evaluator(){
    
}

Evaluator::~Evaluator(){

}

void Evaluator::ingest() {
    std::ifstream eval_file("evaluation_cases.txt");
    if (!eval_file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }
    std::string line;
    std::string str;

    // Go through txt file
    while(std::getline(eval_file, line)){
        // // std::cout << "We are on line: " << line.length() << std::endl;
        // if(line.length() == 1){
        //     // std::cout << "we are in the if statement" << std::endl;
        //     continue;
        // }
        if(line.empty() || line.length() == 1) {
            continue;
        }
        
        str = "";
        line += "\t"; 
        for (char ch : line) {
            if (ch == ' ') {
                if(!str.empty()) {
                    try {
                        int assign = std::stoi(str); 
                        str = "";
                        if(eval_vec_vec.empty()) {
                            std::vector<int> push_vec; 
                            DoublyLinkedList* dll = new DoublyLinkedList(); 
                            eval_vec_vec.push_back(push_vec); 
                            eval_dll_vec.push_back(dll);
                        }
                        eval_vec_vec.back().push_back(assign); 
                        eval_dll_vec.back()->push_back(assign); 
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid number: " << str << std::endl;
                        str = "";
                    }
                }
            }   else if (ch == '\t'){
                if(!str.empty()) {
                    try {
                        int assign = std::stoi(str);
                        str = "";
                        eval_vec_vec.back().push_back(assign);
                        eval_dll_vec.back()->push_back(assign);
                        eval_vec_vec.push_back(std::vector<int>{}); 
                        DoublyLinkedList* tmp = new DoublyLinkedList();
                        eval_dll_vec.push_back(tmp);
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid number: " << str << std::endl;
                        str = "";
                    }
                }
            }   else {
                // string concatenates with ch
                str += ch;
            }
        }
    }
    //string substring

    eval_file.close();
}


void Evaluator::merge_compare(){
    // check if ingested
    if (eval_dll_vec.empty() || eval_vec_vec.empty()) {
        std::cout << "Error: No data to sort. Run ingest() first." << std::endl;
        return;
    }

    // clear previous results
    dll_merge_times.clear();
    vec_merge_times.clear();

    for (size_t i = 0; i < eval_dll_vec.size() - 1; ++i) {
        // skip empty cases
        if (eval_dll_vec[i]->is_empty() || eval_vec_vec[i].empty()) {
            continue;
        }

        // create lists
        DoublyLinkedList* dll_copy = new DoublyLinkedList(*eval_dll_vec[i]);
        std::vector<int> vec_copy = eval_vec_vec[i];

        // dll timer
        auto start = std::chrono::high_resolution_clock::now();
        dll_copy->merge_sort();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dll_duration = end - start;
        dll_merge_times.push_back(dll_duration.count());

        // vec timer
        start = std::chrono::high_resolution_clock::now();
        VectorSorter::merge_sort(vec_copy);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> vec_duration = end - start;
        vec_merge_times.push_back(vec_duration.count());

        delete dll_copy;
    }
}

void Evaluator::quick_compare(){
    // check if ingested
    if (eval_dll_vec.empty() || eval_vec_vec.empty()) {
        std::cout << "Error: No data to sort. Run ingest() first." << std::endl;
        return;
    }

    // clear previous results
    dll_quick_times.clear();
    vec_quick_times.clear();

    for (size_t i = 0; i < eval_dll_vec.size() - 1; ++i) {
        // skip empty cases
        if (eval_dll_vec[i]->is_empty() || eval_vec_vec[i].empty()) {
            continue;
        }

        // create list
        DoublyLinkedList* dll_copy = new DoublyLinkedList(*eval_dll_vec[i]);
        std::vector<int> vec_copy = eval_vec_vec[i];

        // dll timer
        auto start = std::chrono::high_resolution_clock::now();
        dll_copy->quick_sort();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dll_duration = end - start;
        dll_quick_times.push_back(dll_duration.count());

        // vec timer
        start = std::chrono::high_resolution_clock::now();
        VectorSorter::quick_sort(vec_copy);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> vec_duration = end - start;
        vec_quick_times.push_back(vec_duration.count());

        delete dll_copy;
    }
}

void Evaluator::insert_compare(){
    // check if ingested
    if (eval_dll_vec.empty() || eval_vec_vec.empty()) {
        std::cout << "Error: No data to sort. Please run ingest() first." << std::endl;
        return;
    }

    // clear previous results
    dll_insert_times.clear();
    vec_insert_times.clear();

    for (size_t i = 0; i < eval_dll_vec.size() - 1; ++i) {
        // skip empty cases
        if (eval_dll_vec[i]->is_empty() || eval_vec_vec[i].empty()) {
            continue;
        }

        // create lists
        DoublyLinkedList* dll_copy = new DoublyLinkedList(*eval_dll_vec[i]);
        std::vector<int> vec_copy = eval_vec_vec[i];

        // dll timer
        auto start = std::chrono::high_resolution_clock::now();
        dll_copy->insertion_sort();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dll_duration = end - start;
        dll_insert_times.push_back(dll_duration.count());

        // vec timer
        start = std::chrono::high_resolution_clock::now();
        VectorSorter::insertion_sort(vec_copy);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> vec_duration = end - start;
        vec_insert_times.push_back(vec_duration.count());

        delete dll_copy;
    }
}

void Evaluator::evaluate(){

}
//ingest() // delimits on whitespace take in a number delimit, for four lines then update. 
// fill vector with numbers in list, same with doubly linked lists
// variables vector of doubly linked lists and vector and one for the time that it takes from 
//chrono library convert into something more readable
