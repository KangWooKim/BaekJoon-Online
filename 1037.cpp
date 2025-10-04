// https://www.acmicpc.net/problem/1037

#include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    cin >> m;
    vector<int> v(m);
    for(int i = 0 ; i < m ; i++){
        cin >> v[i];
    }
    int a = *max_element(v.begin(), v.end());
    int b = *min_element(v.begin(), v.end());
    
    cout << a * b;
    
    return 0;
}
