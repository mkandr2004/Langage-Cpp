#include "BinarySearch.h"

int BinarySearch::search(std::vector<int>& elements, int target) {
    numberComparisons = 0;
    int left = 0;
    int right = static_cast<int>(elements.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        ++numberComparisons;
        if (elements[mid] == target) return mid;

        ++numberComparisons;
        if (elements[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
