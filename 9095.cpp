// https://www.acmicpc.net/problem/9095

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> dp(11, 0);
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4 ; i < dp.size() ; i++){
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    int T;
    cin >> T;
    while(T--){
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }
    return 0;
}
