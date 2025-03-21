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

int main() {
    std::cout << "Starting Tests" << std::endl;

    std::string vec_result_1 = vector_test_merge_sort() ? "Passed" : "Failed";
    std::cout << "Merge sort: " << vec_result_1 << std::endl;
}