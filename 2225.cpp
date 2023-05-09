// https://www.acmicpc.net/problem/2225

#include <bits/stdc++.h>
#define number 1000000000;
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<vector<int>> dp(201, vector<int>(201, 0));
    
    for(int i = 0 ; i <= 200 ; i++){
        dp[i][1] = 1;
    }
    
    for(int i = 1 ; i <= 200 ; i++)
        dp[0][i] = 1;
    
    for(int i = 1 ; i <= 200 ; i++){
        for(int j = 2 ; j <= 200 ; j++){
            for(int a = 0 ; a <= i ; a++){
                dp[i][j] = (dp[i][j] + dp[a][j - 1]) % number;
            }
        }
    }
    
    cout << dp[N][K];
    return 0;
}
