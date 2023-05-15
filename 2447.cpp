// https://www.acmicpc.net/problem/2447

#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> v;
int n;

void pattern(int a, int x, int y){
    if(a == 3){
        v[x + 1][y + 1] = ' ';
        return;
    }
    
     for(int i = x + a / 3 ; i < x + 2 * a / 3 ; i++){
         for(int j = y + a / 3 ; j < y + 2 * a / 3 ; j++){
             v[i][j] = ' ';
         }
     }
     
    for(int i = x ; i < x + a ; i += a / 3){
        for(int j = y ; j < y + a ; j += a / 3){
            pattern(a / 3, i, j);
        }
    }
    return;
}

int main(){
    cin >> n;
    v = vector<vector<char>>(n, vector<char>(n, '*'));
    pattern(n, 0, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << v[i][j];
        }
        cout << "\n";
    }

    return 0;
}
