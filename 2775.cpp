//https://www.acmicpc.net/problem/2775

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int apartment[15][15] = {0};
    for(int i = 0 ; i < 15 ; i++){
        apartment[0][i] = i;
        apartment[i][1] = 1;
    }
    for(int i = 1 ; i < 15 ; i++){
        for(int j = 1 ; j < 15 ; j++){
            apartment[i][j] = apartment[i - 1][j] + apartment[i][j - 1];
        }
    }
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        int k, n;
        cin >> k; 
        cin >> n;
        cout << apartment[k][n] << '\n';
    }

    return 0;
}
