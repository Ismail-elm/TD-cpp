#include <iostream>
#include "SearchingAlgorithm.h"
#include "Algorithms.h"

int main() {
    std::vector<int> array = {2, 5, 8, 12, 16, 23, 38, 42, 56, 72, 91};
    LinearSearch linear;
    JumpSearch jump;
    BinarySearch binary;

    std::cout << "Linear Search:" << std::endl;
    int result = linear.search(array, 23);
    linear.displaySearchResults(result, 23, std::cout);

    std::cout << "Jump Search:" << std::endl;
    result = jump.search(array, 23);
    jump.displaySearchResults(result, 23, std::cout);

    std::cout << "Binary Search:" << std::endl;
    result = binary.search(array, 23);
    binary.displaySearchResults(result, 23, std::cout);

    return 0;
}
