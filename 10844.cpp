//https://www.acmicpc.net/problem/10844
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j - 1 >= 0) {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            if (j + 1 <= 9) {
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; ++i) {
        result += dp[N][i];
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}
