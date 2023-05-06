// https://www.acmicpc.net/problem/1018

#include <bits/stdc++.h>
using namespace std;

int painting(const vector<string>& v, const int& x, const int& y){
    int B = 0, W = 0;
    for(int i = x ; i < x + 8 ; i++){
        for(int j = y ; j < y + 8 ; j++){
            int sum = i + j;
            if(sum % 2 == 0 && v[i][j] == 'W'){B++;}
            else if(sum % 2 == 0 && v[i][j] == 'B'){W++;}
            else if(sum % 2 == 1 && v[i][j] == 'W'){W++;}
            else if(sum % 2 == 1 && v[i][j] == 'B'){B++;}
        }
    }
    return min(B, W);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<string> v;
    for(int i = 0 ; i < N ; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    int answer = 64;
    for(int x = 0 ; x < N - 7 ; x++){
        for(int y = 0 ; y < M - 7 ; y++){
            answer = min(answer, painting(v, x, y));
        }
    }
    cout << answer;
    return 0;
}
