#include "My_class.h"

#include <iostream>

My_class::My_class() : element("") {}

My_class::My_class(std::string valeur) : element(valeur) {}

void My_class::print_my_element() {
    std::cout << element << std::endl;
}
