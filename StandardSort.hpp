/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Nov 19 2023
StandardSort.hpp implements the standard sort.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int standardSort(vector<int>& nums, int& duration) {
    //get starting time
    auto start = chrono::steady_clock::now();

    //initialize median index
    int n = nums.size()/2;

    //standard sort
    std::sort(nums.begin(), nums.end());

    //get finishing time
    auto end = chrono::steady_clock::now();

    duration = chrono::duration<double, milli> (end - start).count();

    return nums.size()%2 == 0 ? *(nums.begin() + (n-1)) : *(nums.begin() + n);
}