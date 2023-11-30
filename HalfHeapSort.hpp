/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Nov 19 2023
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
    int leftChild;
    int temp = heap[0];

    for(; hole * 2 < heap.size(); hole = leftChild) {
        leftChild = hole * 2;
        if(leftChild + 1 < heap.size() && heap[leftChild] > heap[leftChild + 1]) {
            leftChild++;
        }   
        if(temp > heap[leftChild]) {
            heap[hole] = heap[leftChild];
        }
        else{
            break;
        }
    }

    heap[hole] = temp;
}

void buildHeap(vector<int>& heap) {
    for(int i = (heap.size()-1)/2; i > 0; i--) {
        heap[0] = heap[i];
        percDown(heap, i);
    }
}

int halfHeapSort(vector<int>& nums, int& duration) {
    //get starting time
    auto start = chrono::steady_clock::now();

    //add first element to the back
    nums.push_back(nums[0]);

    //buildHeap
    buildHeap(nums);

    int middle = (nums.size()-2)/2;

    for(int i = 0; i < middle; i++) {
        nums[0] = nums[nums.size() - 1];
        nums.pop_back();
        percDown(nums, 1);
    }

    //get finishing time
    auto end = chrono::steady_clock::now();

    duration = chrono::duration<double, milli> (end - start).count();

    return nums[1];
}
