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

    //if two elements share the same value, make leftmost element the pivot
    if(*left == *center || *left == *right || *center == *right) {
        std::iter_swap(left, right);
        return right;
    }
    else {
        //if left is the median
        if((*center < *left && *left < *right) || (*center > *left && *left > *right)) {
            std::iter_swap(left, right);
        } 
        //if center is the median
        if((*left < *center && *center < *right) || (*left > *center && *center > *right)) {
            std::iter_swap(center, right);
        }
        else{
            return right;
        }
    }
    return right;
}

// hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is
// the last element in the subarray to be partitioned, and is pointed to by high.
// hoarePartition returns an iterator to the pivot after it's placed.
vector<int>::iterator hoarePartition(vector<int>& nums, vector<int>::iterator low, vector<int>::iterator high) {
    //Begin partitioning
    auto pivot = median3(low, high);
    auto i = low, j = pivot-1;

    while(true) {
        while(*i < *pivot) {
            ++i;
        }
        while(*j > *pivot) {
            --j;
        }
        if(std::distance(i, j) > 0) {
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

int quickSelectHelper(vector<int>& nums, vector<int>::iterator low, vector<int>::iterator high, vector<int>::iterator k)  {
    //base case
    if(high <= low + 9){
        std::sort(low, high + 1);
        return *k;
    }

    //partition
    auto pivot = hoarePartition(nums, low, high);

    if(k < pivot) {
        return quickSelectHelper(nums, low, pivot - 1, k);
    }
    else if(k == pivot) {
        return *k;
    }
    return quickSelectHelper(nums, pivot + 1, high, k);
}

int quickSelect(vector<int>& nums, int& duration) {
    auto start = chrono::steady_clock::now();

    //initialize median index
    auto n = nums.begin() + (nums.size()-(nums.size() % 2 == 0 ? 1 : 0))/2;

    int median = quickSelectHelper(nums, nums.begin(), nums.end()-1, n);

    auto end = chrono::steady_clock::now();

    duration = chrono::duration<double, milli>(end - start).count();

    return median;
}