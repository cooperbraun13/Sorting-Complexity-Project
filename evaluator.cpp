#include <iostream>
#include <fstream>
#include "evaluator.hpp"
#include <string>

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
        for (char ch : line) {
            if (ch == ' ') {
                if(!str.empty()){
                int assign = std::stoi(str); 
                str = "";
                if(eval_vec_vec.size() == 0){
                    std::vector<int> push_vec; 
                    DoublyLinkedList dll; 
                    eval_vec_vec.push_back(push_vec); 
                    eval_dll_vec.push_back(dll);
                }
                eval_vec_vec.back().push_back(assign); 
                eval_dll_vec.back().push_back(assign); 
                }
         }  else {
            str += ch;
         }
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
