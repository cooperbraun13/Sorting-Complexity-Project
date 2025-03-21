#ifndef VECTOR_SORTER_HPP
#define VECTOR_SORTER_HPP
#include <vector>

class VectorSorter {
    public:
        void merge_sort(std::vector<int>& nums);
        void quick_sort(std::vector<int>& nums);
        void insertion_sort(std::vector<int>& nums);
    private:
        void merge(std::vector<int>& nums, int left, int mid, int right);
        void merge_sort_helper(std::vector<int>& nums, int left, int right);
        void quick_sort_helper(std::vector<int>& nums, int low, int high);
    };
#endif