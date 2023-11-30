/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Nov 19 2023
HalfSelectionSort.hpp implements the half selection sort.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int halfSelectionSort(vector<int>& nums, int& duration) {
    if(nums.size() > 50000) {
        throw runtime_error("Input size is too large.");
    }

    //get starting time
    auto start = chrono::steady_clock::now();

    //initialize halfway index for vector
    int n = nums.size()/2;

    for(auto it = nums.begin(); it != nums.begin() + n; it++) {
        //Store current index 
        auto minIndex = it;

        for(auto it2 = it+1; it2 != nums.end(); it2++){
            if(*it2 < *minIndex){
                minIndex = it2;
            }
        }

        //swap the stored index with minimum element
        std::iter_swap(it, minIndex);
    }

    //get finishing time
    auto end = chrono::steady_clock::now();

    duration = chrono::duration <double, milli> (end - start).count();

    //return median index/value
    return nums.size()%2 == 0 ? *(nums.begin() + (n-1)) : *(nums.begin() + n);

}