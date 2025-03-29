#ifndef VECTOR_SORTER_HPP
#define VECTOR_SORTER_HPP
#include <vector>

class VectorSorter {
    public:
        static void merge_sort(std::vector<int>& nums);
        static void quick_sort(std::vector<int>& nums);
        static void insertion_sort(std::vector<int>& nums);
        static void merge(std::vector<int>& nums, int left, int mid, int right);
    private:
        static void merge_sort_helper(std::vector<int>& nums, int left, int right);
        static void quick_sort_helper(std::vector<int>& nums, int low, int high);
        static int pivoting(std::vector<int>& nums, int low, int high);

};
#endif