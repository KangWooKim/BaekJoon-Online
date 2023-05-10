// https://www.acmicpc.net/problem/13398

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][1] = v[0]; dp[0][0] = v[0];
    for(int i = 1 ; i < n ; i++){
        dp[i][1] = max(v[i], dp[i - 1][1] + v[i]);
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + v[i]);
    }
    int answer = dp[0][0];
    for(int i=0; i<n; ++i)
        for(int j=0; j<2; ++j)
            answer = max(answer, dp[i][j]);
    cout << answer;
    return 0;
}
