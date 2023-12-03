#include <iostream>
#include <fstream>
#include <vector>

#include "HalfHeapSort.hpp"
#include "HalfSelectionSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "MedianOfMediansMethod.hpp"
#include "MergeSort.hpp"
#include "QuickSelect.hpp"
#include "StandardSort.hpp"
#include "WorstCaseQuickSelect.hpp"

using namespace std;

int main() {
    vector<int> nums;
    int complexity;

    fstream file("input1.txt");

    int num;

    while(file >> num) {
        nums.push_back(num);
    }

    //sorts
    halfSelectionSort(nums, complexity);
    // standardSort(nums, complexity);
    // mergeSort(nums, complexity);
    // inPlaceMergeSort(nums, complexity);
    // halfHeapSort(nums, complexity);
    // quickSelect(nums, complexity);

    cout << complexity;

    return 0;
}