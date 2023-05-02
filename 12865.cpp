// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int N, int K, vector<pair<int, int>>& items) {
    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; ++i) {
        int weight = items[i].first;
        int value = items[i].second;
        for (int j = K; j >= weight; --j) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    return dp[K];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    int result = knapsack(N, K, items);
    cout << result << endl;

    return 0;
}
