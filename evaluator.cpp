#include <iostream>
#include <fstream>
#include "evaluator.hpp"
#include <string>

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

void Evaluator::quick_compare(){

}

void Evaluator::insert_compare(){

}

void Evaluator::evaluate(){

}
//ingest() // delimits on whitespace take in a number delimit, for four lines then update. 
// fill vector with numbers in list, same with doubly linked lists
// variables vector of doubly linked lists and vector and one for the time that it takes from 
//chrono library convert into something more readable
