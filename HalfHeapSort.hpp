/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Oct Nov 19 2023
HalfHeapSort.hpp implements the half heap sort.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown(vector<int>& heap, vector<int>::size_type hole) {
    int child;
    int temp;

    for(temp = std::move(heap[hole]); hole * 2 + 1 < heap.size(); hole = child) {
        child = hole * 2 + 1;
        if(child != heap.size() - 1 && heap[child] < heap[child + 1]) {
            child++;
        }
        if(temp < heap[child]) {
            heap[hole] = std::move(heap[child]);
        }
        else{
            break;
        }
    }
    heap[hole] = std::move(temp);
}

void buildHeap(vector<int>& heap) {
    for(int i = heap.size()/2; i > 0; i--) {
        percDown(heap, i);
    }
}

int halfHeapSort(vector<int>& nums, int& duration) {
    //buildHeap
    buildHeap(nums);

    for(int i = nums.size() - 1; i > 0; i--) {
        std::swap(nums[0], nums[i]);
        percDown(nums, 0);
    }
    
}
