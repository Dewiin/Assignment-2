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

    fstream file("input8.txt");

    int num;

    while(file >> num) {
        nums.push_back(num);
    }

    //sorts
    // halfSelectionSort(nums, complexity);
    // standardSort(nums, complexity);
    // mergeSort(nums, complexity);
    // inPlaceMergeSort(nums, complexity);
    halfHeapSort(nums, complexity);
    // quickSelect(nums, complexity);

    // vector<int> worst = worstCaseQuickSelect();
    // quickSelect(worst, complexity);

    // for(auto i : worst) {
    //     cout << i << " ";
    // }
    
    // for(auto i : nums) {
    //     cout << i << " ";
    // }

    cout << complexity;

    return 0;
}