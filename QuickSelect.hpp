/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Nov 19 2023
QuickSelect.hpp implements the Quick Select method.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

vector<int>::iterator median3(vector<int>::iterator left, vector<int>::iterator right) {
    auto center = left + std::distance(left, right)/2;

    if(*center < *left) {
        std::iter_swap(left, center);
    }
    if(*right < *left) {
        std::iter_swap(left, right);
    }
    if(*right < *center) {
        std::iter_swap(center, right);
    }

    //place pivot at position right - 1
    std::iter_swap(center, std::prev(right));
    
    return std::prev(right);
}

// hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is
// the last element in the subarray to be partitioned, and is pointed to by high.
void hoarePartition(vector<int>& nums, vector<int>::iterator low, vector<int>::iterator high) {
    //pick pivot
    auto pivot = median3(low, high);

    //Begin partitioning
    auto i = low, j = std::prev(high);

    for( ; ; ) {
        while(*i < *pivot) {
            i++;
        }
        while(*pivot < *j) {
            j--;
        }
        if(i < j) {
            std::iter_swap(i, j);
        }
        else {
            break;
        }
    }

    //restore pivot
    std::iter_swap(i, std::prev(high));
}

int quickSelect(vector<int>& nums, int& duration) {
    //initialize median index
    int n = nums.size()/2;

    //base case
    if(nums.size() <= 10){
        std::sort(nums.begin(), nums.end());
        return nums.size()%2 == 0 ? *(nums.begin() + (n-1)) : *(nums.begin() + n);
    }

    //pivot
    auto pivot = median3(nums.begin(), nums.end()-1);
    //S1
    vector<int> S1(nums.begin(), pivot);
    //S2
    vector<int> S2(pivot + 1, nums.end());

    //partition
    hoarePartition(nums, nums.begin(), nums.end()-1);

    if(n < S1.size()) {
        return quickSelect(S1, duration);
    }
    else if(n == S1.size()) {
        return *pivot;
    }
    return quickSelect(S2, duration);

}