#include <iostream>
#include <fstream>
#include "evaluator.hpp"
#include <string>

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
                if (ch == ' ') {  // Ignore spaces
                    eval_vec_vec.push_back(std::vector<int>());
                    eval_dll_vec.push_back(DoublyLinkedList());
                } else{
                int num = ch - '0';  // Convert char to int
                
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
