/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Oct Nov 19 2023
QuickSelect.hpp implements the Quick Select method.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

vector<int>::iterator median3(vector<int> nums, vector<int>::iterator left, vector<int>::iterator right) {
    auto center = left + nums.size()/2;

    if(*center < *left) {
        std::iter_swap(left, center);
    }
    if(*right < *left) {
        std:iter_swap(left, right);
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
    auto pivot = median3(nums, low, high);

    //Begin partitioning
    auto i = low, j = std::prev(high);

    for( ; ; ) {
        while(*(i++) < *pivot) { }
        while(*pivot < *(j--)) { }
        if(i < j) {
            std::iter_swap(i, j);
        }
        else {
            break;
        }
    }

    //restore pivot
    std::iter_swap(i, std::prev(high));

    //sort small elements
    hoarePartition(nums, low, std::prev(i));
    //sort large elements
    hoarePartition(nums, std::next(i), high);
}

int quickSelect(vector<int>& nums, int& duration) {
    if(nums.size() > 1){
        vector<int> smaller;
        vector<int> same;
        vector<int> larger;

        

    }

    //else
    return nums[0];
}