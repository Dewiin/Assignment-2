/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Nov 19 2023
MedianOfMediansMethod.hpp implements the Median of Medians method.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int medianOfFive(vector<int> nums, vector<int>::iterator a, vector<int>::iterator b, vector<int>::iterator c, vector<int>::iterator d, vector<int>::iterator e) {
    vector<int>::iterator temp;

    // makes a < b and b < d
    if(*b < *a){
        temp = a; a = b; b = temp;
    }

    if(*d < *c){
        temp = c; c = d; d = temp;
    }

    // eleminate the lowest
    if(*c < *a){
        temp = b; b = d; d = temp; 
        c = a;
    }

    // gets e in
    a = e;

    // makes a < b and b < d
    if(*b < *a){
        temp = a; a = b; b = temp;
    }

    // eliminate another lowest
    // remaing: a,b,d
    if(*a < *c){
        temp = b; b = d; d = temp; 
        a = c;
    }

    if(*d < *a) {
        return *d;
    }
    return *a;
}

vector<int>::iterator hoarePartition(vector<int> nums, vector<int>::iterator low, vector<int>::iterator high, int pivot) {
    auto i = low, j = high - 1;
    auto it = low;
    while(*it != pivot) {
        it++;
    }
    std::iter_swap(it, high);

    while(true) {
        while(*i < pivot) {
            ++i;
        }
        while(*j > pivot) {
            --j;
        }
        if(std::distance(i, j) > 0) {
            std::iter_swap(i, j);
        }
        else{
            break;
        }
    }

    //restore pivot
    std::iter_swap(i, high);
    return i;
}

// returns the median of medians of all elements contained between high and low, inclusive.
int medianOfMedians(vector<int>& nums, vector<int>::iterator low, vector<int>::iterator high) {
    if(nums.size() > 24) {
        vector<int> medians;

        auto it = low;
        for( ; it+4 < high; it += 5) {
            int median = medianOfFive(nums, it, it+1, it+2, it+3, it+4);
            medians.push_back(median);
        }

        vector<int> temp;
        if(std::distance(it, nums.end()) > 2) {
            while(std::distance(it, nums.end()) > 0) {
                temp.push_back(*it);
                it++;
            }
            std::sort(temp.begin(), temp.end());
            int median = temp[1];
        }

        int pivot = medianOfMedians(medians, medians.begin(), medians.end() - 1);
        auto pivotIndex = hoarePartition(nums, low, high, pivot);




    }
    std::sort(nums.begin(), nums.end());
    return (nums.size()%2 == 0 ? nums[nums.size()/2 - 1] : nums[nums.size()/2]);
}

int medianOfMediansMethod(vector<int>& nums, int& duration) {

}

