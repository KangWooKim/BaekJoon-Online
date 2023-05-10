// https://www.acmicpc.net/problem/1912

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    vector<int> dp(n, 0);
    dp[0] = v[0];
    for(int i = 1 ; i < n ; i++){
        dp[i] = max(dp[i - 1] + v[i], v[i]);
    }
    int answer = *max_element(dp.begin(), dp.end());
    cout << answer;
    return 0;
}
