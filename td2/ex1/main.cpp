//
// Created by MEHDI on 18/10/2024.
//
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int main() {
    vector<int> array = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;

    LinearSearch linearSearch;
    JumpSearch jumpSearch;
    BinarySearch binarySearch;

    int result;

    result = linearSearch.search(array, target);
    linearSearch.displaySearchResults(cout, result, target);

    cout << endl;

    result = jumpSearch.search(array, target);
    jumpSearch.displaySearchResults(cout, result, target);

    cout << endl ;

    result = binarySearch.search(array, target);
    binarySearch.displaySearchResults(cout, result, target);

    cout << endl ;

    cout << "Total comparisons: " << SearchingAlgorithm::totalComparisons << endl;
    cout << "Total searches: " << SearchingAlgorithm::totalSearch << endl;


    return 0;
}