//
// Created by MEHDI on 15/10/2024.
//

#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "SearchingAlgorithm.h"

class LinearSearch: public SearchingAlgorithm{

public:
    LinearSearch()=default;
    virtual ~LinearSearch() = default;
    int search(const vector<int> array, int wanted) override;
};



#endif //LINEARSEARCH_H
