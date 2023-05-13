//https://www.acmicpc.net/problem/14002

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a; cin >> a;
    vector<int> v(a);
    for(int i = 0 ; i < a ; i++){
        cin >> v[i];
    }
    vector<int> answer;
    vector<pair<int, int>> dp(a, make_pair(1, -1));
    for(int i = 0 ; i < a ; i++){
        for(int j = i + 1 ; j < a ; j++){
            if(v[j] > v[i]){
                if(dp[j].first < dp[i].first + 1){
                    dp[j].first = dp[i].first + 1;
                    dp[j].second = i;
                }
            }
        }
    }
    int idx = 0;
    for(int i = 0 ; i < a ; i++){
        if(dp[idx].first < dp[i].first) idx = i;
    }
    answer.push_back(v[idx]); idx = dp[idx].second;
    while(idx != -1){
        answer.push_back(v[idx]);
        idx = dp[idx].second;
    }
    cout << answer.size() << "\n";
    while(!answer.empty()){
        cout << answer.back() << ' ';
        answer.pop_back();
    }
    return 0;
}
