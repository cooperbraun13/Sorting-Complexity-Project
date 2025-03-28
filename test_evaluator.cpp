#include <iostream>
#include <vector>
#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include <cassert>

#include <iostream>
#include <cassert>

bool test_evaluator_ingest() {
    // Setup
    Evaluator eval1;

    // Execution
    std::cout << "executing... " << std::endl;
    eval1.ingest();  // Test for the first line
    std::cout << "passed the call" << std::endl;
    
    //validation
    assert(eval1.eval_vec_vec[0][0] == 1273);
    std::cout << "first vector correct" << std::endl;
    assert(eval1.eval_dll_vec[0]->get_head()->value == 1273);
    std::cout << "first dll correct" << std::endl;
    assert(eval1.eval_vec_vec[0][1] == 4577);
    std::cout << "second vector correct" << std::endl;
    assert(eval1.eval_dll_vec[0]->get_head()->next->value == 4577);
    std::cout << "second dll correct" << std::endl;
    assert(eval1.eval_vec_vec[4][0] == 61407);
    assert(eval1.eval_dll_vec[4]->get_head()->value == 61407);
    std::cout << "ten thousands passed" << std::endl;
    assert(eval1.eval_vec_vec[8][0] == 736525);
    assert(eval1.eval_dll_vec[8]->get_head()->value == 736525);
    std::cout << "Passed hundred thousands" << std::endl;

    std::cout << "Thank god and Luke Johnson we passed our tests" << std::endl;


    return true;
    //cleanup
}

bool test_evaluator_merge_comparison(){
//setup
Evaluator eval1; 
Evaluator eval2;
Evaluator eval3; 

//execution

//validation
return true;
//cleanup
}

bool test_evaluator_quick_comparison(){
return true;
}

bool test_evaluator_insert_comparison(){
return true;
}

bool test_evaluator_evaluate(){
return true;
}

int main(){
test_evaluator_ingest();
//test_evaluator_merge_comparison();
//test_evaluator_quick_comparison();
//test_evaluator_insert_comparison();
//test_evaluator_evaluate();
return 0;
}
