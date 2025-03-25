#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "evaluator.hpp"

Evaluator::Evaluator(){

}

Evaluator::~Evaluator(){

}

void Evaluator::ingest(int amount, int line_num) {
    std::ifstream eval_file("evaluation_cases.txt");  // Open file safely

    if (!eval_file) {  // Check for file open failure
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string line;
    int line_num_start = 0;

    while (std::getline(eval_file, line)) {
        if (line_num_start == line_num) {  
            int vec_count = 0;
            eval_vec_vec.push_back(std::vector<int>());
            eval_dll_vec.push_back(DoublyLinkedList());

            for (char ch : line) {  
                if (ch != ' ') {  // Ignore spaces
                    int num = ch - '0';  // Convert char to int

                    if (eval_vec_vec[vec_count].size() == amount) {  
                        eval_vec_vec.push_back(std::vector<int>());
                        eval_dll_vec.push_back(DoublyLinkedList());
                        vec_count++;
                    }

                    eval_vec_vec[vec_count].push_back(num);
                    eval_dll_vec[vec_count].push_back(num);
                }
            }
            break;  // Stop after processing the target line
        }
        line_num_start++;
    }

    eval_file.close();  // Close the file
}


void Evaluator::merge_compare(){

}

void Evaluator::quick_compare() {
    // if vector empty
    if (eval_dll_vec.empty() || eval_vec_vec.empty()) {
        std::cout << "Error: No data to sort";
        return;
    }
    
    // run tests for each evaluation case
    for (const auto& each_case : evaluation_cases) {
        // create list
        DoublyLinkedList dll_list;
        std::vector<int> vec_list;
        
        for (int num : each_case) {
            dll_list.push_back(num);
            vec_list.push_back(num);
        }
        
        // dll timer
        auto start = std::chrono::high_resolution_clock::now();
        dll_list.quick_sort();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        dll_quick_times.push_back(elapsed.count());
        
        // vector timer
        start = std::chrono::high_resolution_clock::now();
        vec_list.quick_sort();
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        vec_quick_times.push_back(elapsed.count());
    }
}

void Evaluator::insert_compare(){
    // if vector empty
    if (eval_dll_vec.empty() || eval_vec_vec.empty()) {
        std:: cout << "Error: No data to sort";
        return;
    }
    
    // run tests for each evaluation case
    for (const auto& each_case : evaluation_cases) {
        // create lists
        DoublyLinkedList dll_list;
        std::vector<int> vec_list;

        for (int num : each_case) {
            dll_list.push_back(num);
            vec_list.push_back(num);
        }
        
        // dll timer
        auto start = std::chrono::high_resolution_clock::now();
        dll_list.insertion_sort();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        dll_insert_times.push_back(elapsed.count());
        
        // vector timer
        start = std::chrono::high_resolution_clock::now();
        VectorSorter::insertion_sort(vec_list);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        vec_insert_times.push_back(elapsed.count());
    }
}

void Evaluator::evaluate(){
}

//ingest() // delimits on whitespace take in a number delimit, for four lines then update. 
// fill vector with numbers in list, same with doubly linked lists
// variables vector of doubly linked lists and vector and one for the time that it takes from 
//chrono library convert into something more readable
