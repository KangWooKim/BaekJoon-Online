// https://www.acmicpc.net/problem/1932

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        int a; cin >> a; cout << a;
        return 0;
    }
    vector<vector<int>> v(n, vector<int>(n, -1));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            int a; cin >> a;
            v[i - 1][j - 1] = a;
        }
    }
    v[1][0] += v[0][0]; v[1][1] += v[0][0];
    for(int i = 3 ; i <= n ; i++){
        v[i - 1][0] += v[i - 2][0];
        v[i - 1][i - 1] += v[i - 2][i - 2];
        for(int j = 2 ; j <= i - 1 ; j++){
            v[i - 1][j - 1] += max(v[i - 2][j - 1], v[i - 2][j - 2]);
        }
    }
    int answer = *max_element(v[n - 1].begin(), v[n - 1].end());
    cout << answer;
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int>());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int num;
            cin >> num;
            triangle[i].push_back(num);
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    cout << triangle[0][0] << endl;

    return 0;'
}

*/
