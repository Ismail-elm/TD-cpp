#include "Algorithms.h"
#include <cmath>
#include <algorithm>

int LinearSearch::search(const std::vector<int>& v, int target) {
    numberComparisons = 0;
    const int size = static_cast<int>(v.size());

    for (int i = 0; i < size; ++i) {
        ++numberComparisons;
        if (v[i] == target) {
            return i;
        }
    }
    return -1;
}

int JumpSearch::search(const std::vector<int>& v, int target) {
    numberComparisons = 0;
    const int size = static_cast<int>(v.size());
    if (size == 0) return -1;

    const int step = std::max(1, static_cast<int>(std::sqrt(size)));
    int prev = 0;
    int curr = step;

    // Phase 1 : on saute par blocs jusqu'a trouver un bloc dont la fin est >= target
    while (prev < size) {
        const int last = std::min(curr, size) - 1;
        ++numberComparisons;
        if (v[last] >= target) break;
        prev = curr;
        curr += step;
    }
    if (prev >= size) return -1;

    // Phase 2 : recherche lineaire dans le bloc [prev, min(curr, size))
    const int end = std::min(curr, size);
    for (int i = prev; i < end; ++i) {
        ++numberComparisons;
        if (v[i] == target) return i;
        if (v[i] > target) break;
    }
    return -1;
}

int BinarySearch::search(const std::vector<int>& v, int target) {
    numberComparisons = 0;
    int low = 0;
    int high = static_cast<int>(v.size()) - 1;

    while (low <= high) {
        const int mid = low + (high - low) / 2;
        ++numberComparisons;
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
