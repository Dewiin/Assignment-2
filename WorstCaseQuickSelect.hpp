/*
CSCI335 Fall 2023
Assignment 2 – Medians
Name: Devin Xie
Date: Nov 19 2023
WorstCaseQuickSelect.hpp implements the worst case quick select method.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

// worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 
// partitioning. The input it generates must be of length 20,000, and contain each number from 1-20000 once.
vector<int> worstCaseQuickSelect(void) {
    vector<int> worstInput;

    for(int i = 20000; i > 0; i--) {
        worstInput.push_back(i);
    }

    return worstInput;
}