//
// Created by MEHDI on 16/10/2024.
//

//
// Created by MEHDI on 15/10/2024.
//

#include <cmath>

#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"


int LinearSearch::search(const vector<int> array, int wanted) {
    for (int i = 0; i < array.size(); ++i) {
        numberComparaisons++;
        totalComparisons++;
        if (array[i] == wanted) {
            totalSearch++;
            return i;
        }
    }
    totalSearch++;
    return -1;
}

int JumpSearch::search(const vector<int> array, int wanted) {
    size_t n = array.size();
    size_t fenetre = static_cast<int>(sqrt(n));
    int prev = 0;

    while (array[min(fenetre, n) - 1] < wanted) {
        numberComparaisons++;
        totalComparisons++;
        prev = fenetre;
        fenetre += sqrt(n);
        if (prev >= n) {
            totalSearch++;
            return -1;
        }
    }

    for (int i = prev; i < min(fenetre, n); i++) {
        numberComparaisons++;
        totalComparisons++;
        if (array[i] == wanted) {
            totalSearch++;
            return i;
        }
    }
    totalSearch++;
    return -1;
}

int BinarySearch::search(const vector<int> array, int wanted) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        numberComparaisons++;
        totalComparisons++;

        if (array[mid] == wanted) {
            totalSearch++;
            return mid;
        }
        if (array[mid] < wanted) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    totalSearch++;
    return -1;
}
