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

void VectorSorter::quick_sort(std::vector<int>& nums) {
    // base case:
    if (nums.size() <= 1) { // if the length is less than or equal to 1 then return
        return;
    } 
    quick_sort_helper(nums, 0, nums.size()-1); // otherwise, call helper with vector, low (0), and high (length)
}

void VectorSorter::quick_sort_helper(std::vector<int>& nums, int low, int high) {
    if (low < high) { // if the beginning is less than ends
        int pivot_index = pivoting(nums, low, high); // then set the index
        quick_sort_helper(nums, low, pivot_index-1); // call the helper with nums, the first num, and the pivot - 1
        quick_sort_helper(nums, pivot_index+1, high); // call the helper with nums, the pivot + 1, and the last num
    }
}

int VectorSorter::pivoting(std::vector<int>&nums, int low, int high) {
    int pivot = nums[low]; // the first value is selected as the pivot
    int i = low; // set a value to use as the first value
    int j = high; // set a value to use as the last value
    while(i < j) { // while low is less than high
        while (nums[i] <= pivot && i < high) { // while the lowest num is less than or equal to pivot and less than high
            i++; // add one to the low order variable
        } while (nums[j] > pivot) { // while highest num is greater than pivot
            j--; // take away one from the high order variable
        } if (i < j) { // if the low is less than high
            std::swap(nums[i], nums[j]); // swap them
        }
    }
    std::swap(nums[low], nums[j]); // swap the first value and the last value after pivot is selected
    // reduce clutter in test for now std::cout << nums[j] << " ";
    return j;
}

void VectorSorter::insertion_sort(std::vector<int>& nums){ 
    int n = nums.size(); // n is the length of nums
    for (int i = 1; i < n; ++i) { // up until the length of nums
        int key = nums[i]; // the key is the value at nums[i]
        int j = i - 1; // j is the index of values at i
        while (j >= 0 && nums[j] > key) { // while j is less than the key value
            nums[j + 1] = nums[j]; // set the next index to be j
            --j; // take 1 away from j
        }
        nums[j + 1] = key; // i is the key
    }
}