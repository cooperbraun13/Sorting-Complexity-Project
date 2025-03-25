#include <iostream>
#include <fstream>
#include "evaluator.hpp"
#include <string>

Evaluator::Evaluator(){

}

Evaluator::~Evaluator(){

}

void Evaluator::ingest(int line_num) {
    std::ifstream eval_file("evaluation_cases.txt");
    if (!eval_file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string line;
    int current_line = 0;

    // Find the target line
    while (std::getline(eval_file, line) && current_line < line_num) {
        current_line++;
    }

    if (current_line != line_num) {
        std::cerr << "Error: Line number " << line_num << " out of range." << std::endl;
        eval_file.close();
        return;
    }

    // Clear previous data
    eval_vec_vec.clear();
    eval_dll_vec.clear();

    // Start with the first group
    eval_vec_vec.emplace_back();
    eval_dll_vec.emplace_back();

    for (char ch : line) {
        if (ch == ' ') {
            // Add new group
            eval_vec_vec.emplace_back();
            eval_dll_vec.emplace_back();
        } else if (isdigit(ch)) {
            // Add to current group
            int num = ch - '0';
            eval_vec_vec.back().push_back(num);
            eval_dll_vec.back().push_back(num);
        }
    }

    eval_file.close();
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
