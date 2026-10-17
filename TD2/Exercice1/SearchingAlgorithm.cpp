#include "SearchingAlgorithm.h"
#include <iostream>

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() {
    numberComparisons = 0;
}

void SearchingAlgorithm::displaySearchResults(std::ostream& os, int results, int target) {
    ++totalSearch;
    totalComparisons += numberComparisons;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    os << "Valeur recherchee : " << target << '\n';
    if (results == -1) {
        os << "Element introuvable\n";
    } else {
        os << "Indice trouve : " << results << '\n';
    }
    os << "Comparaisons de cette recherche : " << numberComparisons << '\n';
    os << "Total des recherches : " << totalSearch << '\n';
    os << "Total des comparaisons : " << totalComparisons << '\n';
    os << "Moyenne des comparaisons : " << averageComparisons << "\n\n";
}