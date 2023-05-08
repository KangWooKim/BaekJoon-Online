// https://www.acmicpc.net/problem/1003

#include <bits/stdc++.h>
using namespace std;

int main(){
    int TestCase;
    cin >> TestCase;
    vector<vector<int>> v(41, vector<int>(2, 0));
    v[0][0] = 1; v[1][1] = 1;
    for(int i = 2 ; i < v.size() ; i++){
        v[i][0] = v[i - 1][0] + v[i - 2][0];
        v[i][1] = v[i - 1][1] + v[i - 2][1];
    }
    while(TestCase--){
        int N;
        cin >> N;
        cout << v[N][0] << ' ' << v[N][1] << "\n";
    }
    return 0;
}
