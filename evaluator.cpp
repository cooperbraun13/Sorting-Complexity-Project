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
        std::cout << "We are on line: " << line.length() << std::endl;
        if(line.length() == 1){
            std::cout << "we are in the if statement" << std::endl;
            continue;
        }
        str = "";
        line += "\t"; 
        for (char ch : line) {
            if (ch == ' ') {
                if(!str.empty()){
                // if the string isn't empty put it into an integer
                int assign = std::stoi(str); 
                str = "";
                if(eval_vec_vec.size() == 0){
                    // if there's no vector or linked list, make one
                    std::vector<int> push_vec; 
                    DoublyLinkedList dll; 
                    eval_vec_vec.push_back(push_vec); 
                    eval_dll_vec.push_back(dll);
                }
                // add number to the vector and linked lists
                eval_vec_vec.back().push_back(assign); 
                eval_dll_vec.back().push_back(assign); 
                }
            }   else if (ch == '\t'){
                std::cout << "stoi tab" << std::endl;
                int assign = std::stoi(str);
                str = "";
                eval_vec_vec.back().push_back(assign);
                eval_dll_vec.back().push_back(assign);
                std::cout << "end of line found current vector size: " << eval_vec_vec[0].size() << std::endl;
                eval_vec_vec.push_back(std::vector <int>{}); 
                std::cout << "starting to push back doubly linked list" << std::endl;
                DoublyLinkedList tmp;
                eval_dll_vec.push_back(tmp);
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
