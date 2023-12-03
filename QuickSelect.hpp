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

    //place pivot at position right
    std::iter_swap(center, right);
    return right;
}

// hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is
// the last element in the subarray to be partitioned, and is pointed to by high.
// hoarePartition returns an iterator to the pivot after it's placed.
vector<int>::iterator hoarePartition(vector<int>& nums, vector<int>::iterator low, vector<int>::iterator high) {
    //Begin partitioning
    auto pivot = median3(low, high);
    auto i = low, j = high-1;

    for( ; ; ) {
        while(*i < *pivot) { i++; }
        while(*pivot < *j) { j--; }
        if(std::distance(i, j) >= 0) {
            std::iter_swap(i, j);
        }
        else {
            break;
        }
    }

    //restore pivot
    std::iter_swap(i, pivot);
    return i;
}

int quickSelectHelper(vector<int>& nums, int k) {
    //base case
    if(nums.size() <= 10){
        std::sort(nums.begin(), nums.end());
        return nums[k];
    }

    //partition
    auto pivot = hoarePartition(nums, nums.begin(), nums.end()-1);

    //S1
    vector<int> S1(nums.begin(), pivot);
    //S2
    vector<int> S2(pivot + 1, nums.end());

    if(k <= S1.size()) {
        return quickSelectHelper(S1, k);
    }
    else if(k == S1.size() + 1) {
        return *pivot;
    }
    else{
        return quickSelectHelper(S2, k - S1.size() - 1);
    }
}

int quickSelect(vector<int>& nums, int& duration) {
    //initialize median index
    int n = nums.size()/2 + (nums.size()%2 == 0 ? 0 : 1);

    int median = quickSelectHelper(nums, n);

    return median;

    //return nums.size()%2 == 0 ? *(nums.begin() + (n - 1)) : *(nums.begin() + n);
}