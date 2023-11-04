// https://www.acmicpc.net/problem/1034

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M;

    vector<string> table(N);
    for (int i = 0; i < N; ++i) {
        cin >> table[i];
    }
    cin >> K;

    int maxRowsLit = 0;
    // A map to count how many rows have the same configuration.
    map<string, int> patternCount;

    for (int i = 0; i < N; ++i) {
        int zeroCount = 0; // Count of zeros in the current row
        for (char lamp : table[i]) {
            if (lamp == '0') zeroCount++;
        }
        // If we can toggle the whole row and it becomes equal to another row, increment the count
        if (zeroCount <= K && zeroCount % 2 == K % 2) {
            patternCount[table[i]]++;
        }
    }

    // Find the pattern which has the maximum count and satisfies the condition for K toggles
    for (auto &pattern : patternCount) {
        maxRowsLit = max(maxRowsLit, pattern.second);
    }

    cout << maxRowsLit << endl;

    return 0;
}
