#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <ostream>
#include <vector>

class SearchingAlgorithm {
protected:
    int numberComparisons;

    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

public:
    SearchingAlgorithm();
    virtual ~SearchingAlgorithm() = default;
    virtual int search(std::vector<int>& elements, int target) = 0;
    void displaySearchResults(std::ostream& os, int results, int target);
};

#endif
