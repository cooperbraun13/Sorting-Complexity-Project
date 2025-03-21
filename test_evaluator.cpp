#include <iostream>
#include <vector>
#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include <cassert>

bool test_evaluator_ingest(){
//setup
Evaluator eval1;   //100
Evaluator eval2;   //1000
Evaluator eval3;   //10000
Evaluator eval4;   //line 2 100

//execution
eval1.ingest(100, 1); //test for the first line
eval2.ingest(1000, 1); // test for the next size of numbers first line
eval3.ingest(10000, 1); // test for the next size of number 
eval4.ingest(100, 2); //test for the second line

//validation
std::cout << "Eval 1 should output 1273 and 7817" << std::endl;
assert(eval1.eval_vec_vec[0][0] == 1);
assert(eval1.eval_vec_vec[0][1] == 2);
assert(eval1.eval_vec_vec[0][2] == 7); 
assert(eval1.eval_vec_vec[0][3] == 3);
assert(eval1.eval_vec_vec[99][0] == 7);
assert(eval1.eval_vec_vec[99][1] == 8);
assert(eval1.eval_vec_vec[99][2] == 1);
assert(eval1.eval_vec_vec[99][3] == 7);
std::cout << "Eval 2 should output 61407, 65392" << std::endl;
assert(eval2.eval_vec_vec[0][0] == 6);
assert(eval2.eval_vec_vec[0][1] == 1);
assert(eval2.eval_vec_vec[0][2] == 4); 
assert(eval2.eval_vec_vec[0][3] == 0);
assert(eval2.eval_vec_vec[0][4] == 7);
assert(eval2.eval_vec_vec[999][0] == 6);
assert(eval2.eval_vec_vec[999][1] == 5);
assert(eval2.eval_vec_vec[999][2] == 3); 
assert(eval2.eval_vec_vec[999][3] == 9);
assert(eval2.eval_vec_vec[999][4] == 2);
std::cout << "Eval 3 should output 736525 and 601052" << std::endl;
assert(eval3.eval_vec_vec[0][0] == 7);
assert(eval3.eval_vec_vec[1][0] == 3);
assert(eval3.eval_vec_vec[2][0] == 6);
assert(eval3.eval_vec_vec[3][0] == 5);
assert(eval3.eval_vec_vec[4][0] == 2);
assert(eval3.eval_vec_vec[5][0] == 5);
assert(eval3.eval_vec_vec[9999][0] == 6);
assert(eval3.eval_vec_vec[9999][1] == 0);
assert(eval3.eval_vec_vec[9999][2] == 1);
assert(eval3.eval_vec_vec[9999][3] == 0);
assert(eval3.eval_vec_vec[9999][4] == 5);
assert(eval3.eval_vec_vec[9999][5] == 2);
std::cout << "Eval4 should output 6944 and 3156" << std::endl;
assert(eval1.eval_vec_vec[0][0] == 6);
assert(eval1.eval_vec_vec[0][1] == 9);
assert(eval1.eval_vec_vec[0][2] == 4); 
assert(eval1.eval_vec_vec[0][3] == 4);
assert(eval1.eval_vec_vec[99][0] == 3);
assert(eval1.eval_vec_vec[99][1] == 1);
assert(eval1.eval_vec_vec[99][2] == 5);
assert(eval1.eval_vec_vec[99][3] == 6);

//cleanup

//ingest() // delimits on whitespace take in a number delimit, for four lines then update. 
// fill vector with numbers in list, same with doubly linked lists
// variables vector of doubly linked lists and vector and one for the time that it takes from 
//chrono library convert into something more readable
}

bool test_evaluator_merge_comparison(){
//setup
Evaluator eval1; 
Evaluator eval2;
Evaluator eval3; 

//execution

//validation

//cleanup
}

bool test_evaluator_quick_comparison(){

}

bool test_evaluator_insert_comparison(){

}

bool test_evaluator_evaluate(){

}

int main(){
test_evaluator_ingest();
test_evaluator_merge_comparison();
test_evaluator_quick_comparison();
test_evaluator_insert_comparison();
test_evaluator_evaluate();
}
