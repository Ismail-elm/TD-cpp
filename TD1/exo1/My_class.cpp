#include "My_class.h"

My_class::My_class(std::string input) {
    my_element = input;
}

std::string My_class::print_my_element() {
    return my_element;
}