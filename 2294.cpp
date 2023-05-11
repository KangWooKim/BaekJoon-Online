// https://www.acmicpc.net/problem/2294

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    for(int i = 0 ; i < n ; i++)
        cin >> coin[i];
    vector<int> dp(k + 1, 987654321);
    for(auto& c : coin){
        dp[c] = 1;
        for(int i = 1 ; i + c <= k ; i++){
            if(dp[i] == -1) continue;
            if(dp[i + c] > dp[i] + 1) dp[i + c] = dp[i] + 1;
        }
    }
    if(dp[k] == 987654321) cout << -1;
    else cout << dp[k];
    return 0;
}
