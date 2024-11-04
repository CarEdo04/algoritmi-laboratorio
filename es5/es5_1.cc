#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> findLongestUncoveredPeriod(int intervals[][2], int N) {
    if (N == 0) {
        return {0, 0};
    }

    // Ordinare gli intervalli in base all'inizio
    sort(intervals, intervals + N, [](const int a[2], const int b[2]) {
        return a[0] < b[0];
    });

    int currentEnd = intervals[0][1];
    int longestLength = 0;
    pair<int, int> longestUncovered = {0, 0};

    // Controllare il periodo prima del primo intervallo
    if (intervals[0][0] > 0) {
        longestLength = intervals[0][0];
        longestUncovered = {0, intervals[0][0]};
    }

    // Controllare gli spazi tra gli intervalli
    for (int i = 1; i < N; ++i) {
        if (intervals[i][0] > currentEnd) {
            int uncoveredLength = intervals[i][0] - currentEnd;
            if (uncoveredLength > longestLength) {
                longestLength = uncoveredLength;
                longestUncovered = {currentEnd, intervals[i][0]};
            }
        }
        // Aggiornare l'end corrente se c'è sovrapposizione
        currentEnd = max(currentEnd, intervals[i][1]);
    }

    // Non controlliamo il periodo dopo l'ultimo intervallo
    return longestLength > 0 ? longestUncovered : make_pair(0, 0);
}

int main() {
    const int MAX_INTERVALS = 1000; // Definire un numero massimo di intervalli
    int intervals[MAX_INTERVALS][2];
    int N;

    cout << "Inserisci il numero di intervalli (max " << MAX_INTERVALS << "): ";
    cin >> N;

    if (N > MAX_INTERVALS) {
        cout << "Numero di intervalli supera il massimo consentito." << endl;
        return 1;
    }

    cout << "Inserisci gli intervalli (inizio fine): " << endl;
    for (int i = 0; i < N; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    pair<int, int> result = findLongestUncoveredPeriod(intervals, N);

    if (result.first == 0 && result.second == 0) {
        cout << 0 << endl;
    } else {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}