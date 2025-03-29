#include <iostream>
#include <vector>
#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"
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
    // setup
    std::cout << "\nStarting Merge comparison test.\n";
    Evaluator eval;

    eval.ingest();
    std::cout << "Ingest completed.\n";

    DoublyLinkedList* dll_original = eval.eval_dll_vec[0];
    DoublyLinkedList dll_copy(*dll_original);
    dll_copy.merge_sort();
    std::cout << "DLL Merge sort completed.\n";

    std::vector<int> vec_original = eval.eval_vec_vec[0];
    std::vector<int> vec_copy = vec_original;
    VectorSorter::merge_sort(vec_copy);
    std::cout << "Vector merge sort completed.\n";

    // execution
    eval.merge_compare();

    // validation
    assert(!eval.dll_merge_times.empty() && !eval.vec_merge_times.empty());
    std::cout << "- DLL: " << eval.dll_merge_times[0] << " sec\n";
    std::cout << "- Vector: " << eval.vec_merge_times[0] << " sec\n";
    std::cout << "Merge comparison test passed.\n";
    
    // cleanup
    return true;
}

bool test_evaluator_quick_comparison() {
    // setup
    std::cout << "\nStarting Quick comparison test.\n";
    Evaluator eval;

    eval.ingest();
    std::cout << "Ingest completed.\n";

    DoublyLinkedList* dll_original = eval.eval_dll_vec[0];
    DoublyLinkedList dll_copy(*dll_original);
    dll_copy.quick_sort();
    std::cout << "DLL quick sort completed.\n";

    std::vector<int> vec_original = eval.eval_vec_vec[0];
    std::vector<int> vec_copy = vec_original;
    VectorSorter::quick_sort(vec_copy);
    std::cout << "Vector quick sort completed.\n";

    // execution
    eval.quick_compare();

    // validation
    assert(!eval.dll_quick_times.empty() && !eval.dll_quick_times.empty());
    std::cout << "- DLL: " << eval.dll_quick_times[0] << " sec\n";
    std::cout << "- Vector: " << eval.dll_quick_times[0] << " sec\n";
    std::cout << "Insertion comparison test passed.\n";
    
    // cleanup
    return true;
}

bool test_evaluator_insert_comparison() {
    // setup
    std::cout << "\nStarting Insert comparison test.\n";
    Evaluator eval;

    eval.ingest();
    std::cout << "Ingest completed.\n";

    DoublyLinkedList* dll_original = eval.eval_dll_vec[0];
    DoublyLinkedList dll_copy(*dll_original);
    dll_copy.insertion_sort();
    std::cout << "DLL insertion sort completed.\n";

    std::vector<int> vec_original = eval.eval_vec_vec[0];
    std::vector<int> vec_copy = vec_original;
    VectorSorter::insertion_sort(vec_copy);
    std::cout << "Vector insertion sort completed.\n";

    // execution
    eval.insert_compare();

    // validation
    assert(!eval.dll_insert_times.empty() && !eval.vec_insert_times.empty());
    std::cout << "- DLL: " << eval.dll_insert_times[0] << " sec\n";
    std::cout << "- Vector: " << eval.vec_insert_times[0] << " sec\n";
    std::cout << "Insertion comparison test passed.\n";
    
    // cleanup
    return true;
}

bool test_evaluator_evaluate(){
return true;
}

int main(){
    test_evaluator_ingest();
    test_evaluator_merge_comparison();
    test_evaluator_quick_comparison();
    test_evaluator_insert_comparison();
    //test_evaluator_evaluate();
    return 0;
}
