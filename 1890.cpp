// https://www.acmicpc.net/problem/1890

#include <bits/stdc++.h>
using namespace std;
int N;
int mp[101][101];
vector<vector<long long>> v;

bool InRange(const int& x, const int& y){
    return x >= 0 && y >= 0 && x < N && y < N;
}

long long dfs(int y, int x){
    if(!InRange(y, x)) return 0;
    if(x == N - 1 && y == N - 1) return 1;
    if(mp[y][x] == 0) return 0;
    if(v[y][x] != -1) return v[y][x];
    return v[y][x] = dfs(y, x + mp[y][x]) + dfs(y + mp[y][x], x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        vector<long long> x;
        for(int j = 0 ; j < N ; j++){
            int val; cin >> val;
            mp[i][j] = val; x.push_back(-1);
        }
        v.push_back(x);
    }
    cout << dfs(0, 0);
    
    return 0;
}
