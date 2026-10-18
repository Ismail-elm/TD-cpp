#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() {
    numberComparisons = 0;
}

void SearchingAlgorithm::displaySearchResults(int results, int target, std::ostream& os) {
    totalComparisons += numberComparisons;
    ++totalSearch;
    if (totalSearch == 0) {
        averageComparisons = 0.0;
    } else {
        averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    }

    if (results >= 0) {
        os << "Element " << target << " trouve a l'indice " << results;
    } else {
        os << "Element " << target << " absent du vecteur";
    }
    os << " en " << numberComparisons << " comparaison(s)\n";
    os << "  Total : " << totalComparisons << " comparaisons sur "
       << totalSearch << " recherche(s), moyenne = " << averageComparisons << "\n";

}