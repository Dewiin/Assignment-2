/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Nov 19 2023
InPlaceMergeSort.hpp implements the merge sort in place.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

void inPlaceHelper(vector<int>::iterator first, vector<int>::iterator last) {
    //if size is greater than 1
    if(last - first > 1) {
        auto middle = first + (last - first) / 2;
        inPlaceHelper(first, middle);
        inPlaceHelper(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

int inPlaceMergeSort(vector<int>& nums, int& duration) {
    //get start time
    auto start = chrono::steady_clock::now();

    //initialize iterators
    auto first = nums.begin(), last = nums.end();

    inPlaceHelper(first, last);

    //initialize median index
    int n = nums.size()/2;

    //get finishing time
    auto end = chrono::steady_clock::now();
    duration = chrono::duration<double, milli> (end - start).count();

    //return median value
    return nums.size()%2 == 0 ? *(nums.begin() + (n-1)) : *(nums.begin() + n);
}
