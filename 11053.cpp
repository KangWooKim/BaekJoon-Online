// https://www.acmicpc.net/problem/11053

#include <bits/stdc++.h>
using namespace std;

int main() {
    int len;
    cin >> len;
    vector<int> v(len);

    for (int i = 0; i < len; i++) {
        cin >> v[i];
    }

    vector<int> dp(len, 1);

    for (int i = 1; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
