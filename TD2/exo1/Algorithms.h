#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>
#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm {
    public:
        int search(const std::vector<int>& array, int target) override;
};

class JumpSearch : public SearchingAlgorithm {
    public:
        int search(const std::vector<int>& array, int target) override;
};

class BinarySearch : public SearchingAlgorithm {
    public:
        int search(const std::vector<int>& array, int target) override;
};

#endif

