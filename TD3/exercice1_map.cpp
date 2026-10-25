#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); i++) {
        bool dejaVu = false;
        for (size_t j = 0; j < i; j++) {
            if (numbers[j] == numbers[i]) {
                dejaVu = true;
                break;
            }
        }
        if (dejaVu) continue;

        int count = 0;
        for (size_t k = 0; k < numbers.size(); k++) {
            if (numbers[k] == numbers[i]) count++;
        }
        cout << numbers[i] << ": " << count << " times" << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> freq;
    for (int n : numbers) {
        freq[n]++;
    }
    return freq;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 4, 1, 5, 5, 5, 6};

    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBruteForce(numbers);

    cout << "\nFrequency (Optimal):" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << ": " << entry.second << " times" << endl;
    }

    return 0;
}
