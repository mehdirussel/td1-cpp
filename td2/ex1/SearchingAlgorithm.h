//
// Created by MEHDI on 11/10/2024.
//

#pragma once

#include <iostream>
#include <vector>
using namespace std;


class SearchingAlgorithm {
protected:
        int numberComparaisons;

public:
        virtual ~SearchingAlgorithm() = default;

        static int totalComparisons;
        static int totalSearch;
        static int averageComparaisons;
    

        SearchingAlgorithm();
        virtual int search(const vector<int> array, int wanted) = 0;
        void displaySearchResults(ostream& os,int results, int target) const;


 };
