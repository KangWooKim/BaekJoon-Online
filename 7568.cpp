// https://www.acmicpc.net/problem/7568

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for(int i = 0 ; i < N ; i++){
        int w, h;
        cin >> w >> h;
        v.push_back(make_pair(w, h));
    }
    for(int i = 0 ; i < N ; i++){
        int grade = 1;
        for(int j = 0 ; j < N ; j++){
            if(v[j].first > v[i].first && v[j].second > v[i].second) ++grade;
        }
        cout << grade;
        if(i != N - 1) cout << ' ';
    }
    return 0;
}
