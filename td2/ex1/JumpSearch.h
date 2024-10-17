//
// Created by MEHDI on 15/10/2024.
//

#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include "SearchingAlgorithm.h"

class JumpSearch: public SearchingAlgorithm{
    public:
    JumpSearch()=default;
    virtual ~JumpSearch() = default;
    int search(const vector<int> array, int wanted) override;
};



#endif //JUMPSEARCH_H
