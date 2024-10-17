//
// Created by MEHDI on 15/10/2024.
//

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch: public SearchingAlgorithm{
public:
    BinarySearch()=default;
    virtual ~BinarySearch() = default;
    int search(const vector<int> array, int wanted) override;
};



#endif //BINARYSEARCH_H
