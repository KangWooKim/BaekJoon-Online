// https://www.acmicpc.net/problem/11726

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(1001, 0);
    v[1] = 1; v[2] = 2;
    for(int i = 3 ; i < 1001 ; i++){
        v[i] = (v[i - 1] + v[i - 2]) % 10007;
    }
    cout << v[n];
    return 0;
}
