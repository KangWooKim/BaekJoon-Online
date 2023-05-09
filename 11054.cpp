// https://www.acmicpc.net/problem/11054

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> l(N, 0);
    for(int i = 0 ; i < N ; i++){
        int a; cin >> a;
        l[i] = a;
    }
    vector<vector<int>> dp(N, vector<int>(2, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = i + 1 ; j < N ; j++){
            if(l[j] > l[i]) dp[j][0] = max(dp[j][0], dp[i][0] + 1);
        }
    }
    for(int i = N - 1 ; i >= 0 ; i--){
        for(int j = 0 ; j < i ; j++){
            if(l[j] > l[i]) dp[j][1] = max(dp[j][1], dp[i][1] + 1);
        }
    }
    int answer = 0;
    for(int i = 0 ; i < N ; i++){
        int sum = dp[i][0] + dp[i][1];
        answer = answer < sum ? sum : answer;
    }
    cout << ++answer;
    return 0;
}
