// https://www.acmicpc.net/problem/11660

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
    for(int i = 1 ; i < v.size() ; i++){
        for(int j = 1 ; j < v.size() ; j++){
            int val; cin >> val;
            v[i][j] = val;
        }
    }
    vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));
    for(int i = 1 ; i < v.size() ; i++){
        for(int j = 1 ; j < v.size() ; j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i][j];
        }
    }
    while(M--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2 && y1 == y2) cout << v[x1][y1] << "\n";
        else{
            int k = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
            cout << k << "\n";
        }
    }
    return 0;
}
