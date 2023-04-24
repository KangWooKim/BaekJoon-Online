// https://www.acmicpc.net/problem/1149

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(3));
    dp[0] = cost[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int answer = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << answer;

    return 0;
}
