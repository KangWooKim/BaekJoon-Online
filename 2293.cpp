// https://www.acmicpc.net/problem/2293

#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    std::vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= k; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    std::cout << dp[k] << std::endl;

    return 0;
}
