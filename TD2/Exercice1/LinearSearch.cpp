#include "LinearSearch.h"

int LinearSearch::search(std::vector<int>& elements, int target) {
    numberComparisons = 0;
    for (int i = 0; i < static_cast<int>(elements.size()); ++i) {
        ++numberComparisons;
        if (elements[i] == target) {
            return i;
        }
    }
    return -1;
}
