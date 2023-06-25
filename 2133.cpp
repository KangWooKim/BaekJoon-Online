// https://www.acmicpc.net/problem/2133

#include <iostream>
using namespace std;

int dp[31] = {1, 0, 3};

int main() {
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
    }
    cout << dp[n];
    return 0;
}
