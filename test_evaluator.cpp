#include <iostream>
#include <vector>
#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include <cassert>

#include <iostream>
#include <cassert>

bool test_evaluator_ingest() {
    // Setup
    Evaluator eval1;  // 100
    Evaluator eval2;  // 1000
    Evaluator eval3;  // 10000
    Evaluator eval4;  // line 2, 100

    // Execution
    std::cout << "executing... " << std::endl;
    eval1.ingest(0);  // Test for the first line
    //eval2.ingest(5); // Test for the next size of numbers first line
    //eval3.ingest(10); // Test for the next size of numbers
    //eval4.ingest(1); // Test for the second line

    // Validation
    std::cout << "eval1 size: " << eval1.eval_vec_vec.size() << std::endl;
    std::cout << "eval2 size: " << eval2.eval_vec_vec.size() << std::endl;
    std::cout << "eval3 size: " << eval3.eval_vec_vec.size() << std::endl;
    std::cout << "eval1 value 1: " << eval1.eval_vec_vec[0][0] << std::endl;

    assert(eval1.eval_vec_vec.size() >= 100);
    std::cout << "Eval1 size passed" << std::endl;
    assert(eval2.eval_vec_vec.size() >= 1000);
    std::cout << "Eval2 size passed" << std::endl;
    assert(eval3.eval_vec_vec.size() >= 10000);
    std::cout << "Eval3 size passed" << std::endl;

    assert(eval1.eval_vec_vec[0][0] == 1);
    assert(eval1.eval_vec_vec[0][1] == 2);
    assert(eval1.eval_vec_vec[0][2] == 7);
    assert(eval1.eval_vec_vec[0][3] == 3);
    std::cout << "Eval1 val check [0] passed" << std::endl;

    assert(eval1.eval_vec_vec[99][0] == 7);
    assert(eval1.eval_vec_vec[99][1] == 8);
    assert(eval1.eval_vec_vec[99][2] == 1);
    assert(eval1.eval_vec_vec[99][3] == 7);
    std::cout << "Eval1 val check [99] passed" << std::endl;

    assert(eval2.eval_vec_vec[0][0] == 6);
    assert(eval2.eval_vec_vec[0][1] == 1);
    assert(eval2.eval_vec_vec[0][2] == 4);
    assert(eval2.eval_vec_vec[0][3] == 0);
    assert(eval2.eval_vec_vec[0][4] == 7);
    std::cout << "Eval2 val check [0] passed" << std::endl;

    assert(eval2.eval_vec_vec[999][0] == 6);
    assert(eval2.eval_vec_vec[999][1] == 5);
    assert(eval2.eval_vec_vec[999][2] == 3);
    assert(eval2.eval_vec_vec[999][3] == 9);
    assert(eval2.eval_vec_vec[999][4] == 2);
    std::cout << "Eval2 val check [999] passed" << std::endl;

    assert(eval3.eval_vec_vec[0][0] == 7);
    assert(eval3.eval_vec_vec[1][0] == 3);
    assert(eval3.eval_vec_vec[2][0] == 6);
    assert(eval3.eval_vec_vec[3][0] == 5);
    assert(eval3.eval_vec_vec[4][0] == 2);
    assert(eval3.eval_vec_vec[5][0] == 5);
    std::cout << "Eval3 val check [0] passed" << std::endl;

    assert(eval3.eval_vec_vec[9999][0] == 6);
    assert(eval3.eval_vec_vec[9999][1] == 0);
    assert(eval3.eval_vec_vec[9999][2] == 1);
    assert(eval3.eval_vec_vec[9999][3] == 0);
    assert(eval3.eval_vec_vec[9999][4] == 5);
    assert(eval3.eval_vec_vec[9999][5] == 2);
    std::cout << "Eval3 val check [9999] passed" << std::endl;
    // Cleanup
    return true;
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
