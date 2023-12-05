/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Nov 19 2023
MergeSort.hpp implements the merge sort.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

void mergeSort_helper(vector<int>& nums) {
    //base case
    if(nums.size() <= 1) {
        return;
    }

    //initialize median index
    auto n = nums.begin() + nums.size()/2;

    //vector for storing left half values
    vector<int> left(nums.begin(), n); 
    //vector for storing right half values
    vector<int> right(n , nums.end());

    //recursive splitting
    mergeSort_helper(left);
    mergeSort_helper(right);

    //clear nums
    nums.clear();

    //MERGING
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(nums));
}

int mergeSort(vector<int>& nums, int& duration) {
    //get start time
    auto start = chrono::steady_clock::now();

    int n = nums.size()/2;

    mergeSort_helper(nums);

    //get finishing time
    auto end = chrono::steady_clock::now();

    duration = chrono::duration<double, milli> (end - start).count();

    //return median value
    return nums.size()%2 == 0 ? *(nums.begin() + (n-1)) : *(nums.begin() + n);
}