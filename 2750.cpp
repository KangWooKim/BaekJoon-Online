//https://www.acmicpc.net/problem/2750

#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt;
    vector<int> list;
    cin >> cnt;
    for(int i = 0 ; i < cnt ; i++){
        int k = 0;
        cin >> k;
        list.push_back(k);
    }
    sort(list.begin(), list.end());
    for(int i = 0 ; i < list.size() ; i++){
        cout << list[i] << '\n';
    }
    return 0;
}
