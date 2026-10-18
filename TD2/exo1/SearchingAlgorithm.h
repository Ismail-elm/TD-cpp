#include <iostream>
#include <vector>
#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

class SearchingAlgorithm {
    public :
        SearchingAlgorithm();
        virtual ~SearchingAlgorithm() = default;
        virtual int search(const std::vector<int>& array, int target) = 0;
        void displaySearchResults(int results, int target, std::ostream& os);
    protected :
        int numberComparisons;
        static int totalComparisons;
        static int totalSearch;
        static double averageComparisons;
};

#endif