#include "JumpSearch.h"

#include <algorithm>
#include <cmath>

int JumpSearch::search(std::vector<int>& elements, int target) {
    numberComparisons = 0;
    const int n = static_cast<int>(elements.size());
    if (n == 0) return -1;

    const int step = std::max(1, static_cast<int>(std::sqrt(n)));
    int start = 0;
    int end = step;

    while (start < n) {
        const int last = std::min(end, n) - 1;
        ++numberComparisons;
        if (elements[last] >= target) break;
        start = end;
        end += step;
    }

    for (int i = start; i < std::min(end, n); ++i) {
        ++numberComparisons;
        if (elements[i] == target) return i;
    }
    return -1;
}
