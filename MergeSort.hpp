/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Oct Nov 19 2023
MergeSort.hpp implements the merge sort.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int mergeSort(vector<int>& nums, int& duration) {
    //base case
    if(nums.size() <= 1) {
        return 0;
    }

    //vector for storing left half values
    vector<int> left; 
    //vector for storing right half values
    vector<int> right;

    //initialize median index
    int n = nums.size()/2;

    for(auto it = nums.begin(); it != nums.end(); it++) {
        if(it < nums.begin() + n) {
            left.push_back(*it);
        }
        else {
            right.push_back(*it);
        }
    }

    //recursive splitting
    mergeSort(left, duration);
    mergeSort(right, duration);

    //clear nums
    nums.clear();

    //MERGING
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(nums));

    //return median value
    return nums.size()%2 == 0 ? *(nums.begin() + (n-1)) : *(nums.begin() + n);
}