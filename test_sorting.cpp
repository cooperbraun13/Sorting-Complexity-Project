#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include "vector_sorter.hpp"

bool vector_test_merge_sort() {
    // test for an empty vector, a length of one, and a length of many nums
    // set up
    VectorSorter sorter; // make an instance of the object
    std::vector<int> empty; 
    std::vector<int> single = {5};
    std::vector<int> nums = {3, 6, 2, 1, 4};

    // execution
    sorter.merge_sort(empty); // call a sort on the empty vector
    sorter.merge_sort(single); // call a sort of the one-value vector
    sorter.merge_sort(nums); // call a sort on the vector of numbers

    // validation
    assert(empty.empty()); // assert that empty is still empty
    assert(single.size() == 1 && single[0] == 5); // assert that the single value vector is still five and length of one
    assert(std::is_sorted(nums.begin(), nums.end())); // assert that nums is sorted in ascending order

    // clean up
    return true;
}

bool vector_test_quick_sort() {
    // test for an empty vector, a length of one, and a length of many nums
    // set up
    VectorSorter sorter;
    std::vector<int> empty;
    std::vector<int> single = {7};
    std::vector<int> nums = {9, 3, 2, 5, 6};

    // execution
    sorter.quick_sort(empty);
    sorter.quick_sort(single);
    sorter.quick_sort(nums);

    // validation
    assert(empty.empty());
    assert(single.size() == 1 && single[0] == 7);
    assert(std::is_sorted(nums.begin(), nums.end()));

    // clean up
    return true;
}

bool vector_test_insertion_sort() {
    // test for an empty vector, a length of one, and a length of many nums
    // set up
    VectorSorter sorter;
    std::vector<int> empty;
    std::vector<int> single = {2};
    std::vector<int> nums = {8, 4, 1, 2, 5};

    // execution
    sorter.insertion_sort(empty);
    sorter.insertion_sort(single);
    sorter.insertion_sort(nums);

    // validation
    assert(empty.empty());
    assert(single.size() == 1 && single[0] == 2);
    assert(std::is_sorted(nums.begin(), nums.end()));

    // clean up
    return true;
}

int main() {
    std::cout << "Starting Tests" << std::endl;

    std::string vec_result_1 = vector_test_merge_sort() ? "Passed" : "Failed";
    std::cout << "Merge sort: " << vec_result_1 << std::endl;

    std::cout << "\tPivot order: ";
    std::string vec_result_2 = vector_test_quick_sort() ? "Passed" : "Failed";
    std::cout << "\nQuick sort: " << vec_result_2 << std::endl;

    std::string vec_result_3 = vector_test_insertion_sort() ? "Passed" : "Failed";
    std::cout << "Insertion sort: " << vec_result_3 << std::endl;
}