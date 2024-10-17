#include "SearchingAlgorithm.h"

#include <cstring>
#include <iostream>


int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
int SearchingAlgorithm::averageComparaisons = 0;


SearchingAlgorithm::SearchingAlgorithm():numberComparaisons(0){};

void SearchingAlgorithm::displaySearchResults(ostream &os, int results, int target) const {


    os << "target " << target << ((results == -1) ? " not found in array" : " found at index: " + std::to_string(results)) << std::endl;

    os << "numberComparaisons: " << numberComparaisons << endl;
    os << "totalComparaisons: " << totalComparisons << endl;
    os << "totalSearch: " << totalSearch << endl;
    os << "numberComparaisons: " << numberComparaisons << endl;

}
