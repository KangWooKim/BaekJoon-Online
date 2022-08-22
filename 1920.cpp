// https://www.acmicpc.net/problem/1920

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a; long long b;
    set<long long> s1;
    vector<long long> v;
    cin >> a;
    for(int i = 0 ; i < a ; i++){
        cin >> b; s1.insert(b);
    }
    cin >> a;
    for(int i = 0 ; i < a ; i++){
        cin >> b; v.push_back(b);
    }
    for(auto i : v){
        int k = s1.count(i);
        cout << k << '\n';
    }
    return 0;
}
