#include <iostream>
#include <vector>
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int main() {
    std::vector<int> elements = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int target = 50;

    LinearSearch linear;
    JumpSearch jump;
    BinarySearch binary;

    std::cout << "=== LINEAR SEARCH ===\n";
    int result = linear.search(elements, target);
    linear.displaySearchResults(std::cout, result, target);

    std::cout << "=== JUMP SEARCH ===\n";
    result = jump.search(elements, target);
    jump.displaySearchResults(std::cout, result, target);

    std::cout << "=== BINARY SEARCH ===\n";
    result = binary.search(elements, target);
    binary.displaySearchResults(std::cout, result, target);

    std::cout << "=== VALEUR ABSENTE ===\n";
    target = 100;
    result = binary.search(elements, target);
    binary.displaySearchResults(std::cout, result, target);

    return 0;
}
