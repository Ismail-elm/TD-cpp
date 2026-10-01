#include <iostream>
#include "My_class.h"
#include "function.h"

int main() {
    // ex 1 - 1 : std::cout << "Hello, World!" << std::endl
    // ex 1 - 2 : std::cout << function("Hello, World!") << std::endl;
    My_class obj("Hello, World!");
    std::cout << obj.print_my_element() << std::endl;
} 