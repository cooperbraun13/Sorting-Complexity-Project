#include <stdexcept>
#include <iostream>
#include <vector>
#include "vector_sorter.hpp"

void VectorSorter::merge_sort(std::vector<int>& nums) {
    if (nums.size() > 1) {
        merge_sort_helper(nums, 0, nums.size() - 1);
    }
}

void VectorSorter::merge_sort_helper(std::vector<int>& nums, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 
        merge_sort_helper(nums, left, mid); // recursive with the new mid value as the end (L)
        merge_sort_helper(nums, mid + 1, right); // recursive again with the new mid value to the end of the right (R)
        merge(nums, left, mid, right); // merge the two together yay!
    }
}

void VectorSorter::merge(std::vector<int>& nums, int left, int mid, int right) {
    std::vector<int> left_half(nums.begin() + left, nums.begin() + mid + 1); // left half vector
    std::vector<int> right_half(nums.begin() + mid + 1, nums.begin() + right + 1); // right half vector
    int i = 0, j = 0, k = left; 
    while (i < left_half.size() && j < right_half.size()) {
        if (left_half[i] <= right_half[j]) { // if the value at the beginning of the left is less than beginning value of right
            nums[k] = left_half[i]; // then add it to the left half vector
            i++;
        } else {
            nums[k] = right_half[j]; // otherwise add the value to the right half vector
            j++;
        } 
        k++; // then increase the index we add to
    } while (i < left_half.size()) { // while i is less than length of left half
        nums[k] = left_half[i]; // then assign nums at k to the value at i in left half
        i++; // add to the indexes
        k++;
    } while (j < right_half.size()) { // while j is less than length of right half
        nums[k] = right_half[j]; // then assign nums at k to the value at j in right half
        j++; // add to the indexes
        k++;
    }
}