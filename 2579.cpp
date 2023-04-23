//https://www.acmicpc.net/problem/2579

#include <bits/stdc++.h>
using namespace std;

int answer(int n, vector<int>& max_score, vector<int>& s){
    if(n == 0) return s[0];
    if(n == 1){
        if(max_score[1] == -1)
            max_score[1] = s[1];
        return max_score[1];
    }
    if(n == 2){
        if(max_score[2] == -1){
            max_score[2] = s[2] + s[1];
        }
        return max_score[2];
    }
    else{
        if(max_score[n] == -1){
            int first = answer(n - 2, max_score, s);
            int second = answer(n - 3, max_score, s) + s[n - 1];
            max_score[n] = max(first, second) + s[n];
        }
        return max_score[n];
    }
}

int main(){
    vector<int> s;
    int score; int size;
    cin >> size;
    s.push_back(0);
    while(cin >> score){
        s.push_back(score);
    }
    vector<int> max_score(size + 1, -1);
    max_score[0] = 0;
    int ans = answer(size, max_score, s);
    cout << ans;
}
