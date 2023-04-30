// https://www.acmicpc.net/problem/11650

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> list;
    while(N--){
        int x, y;
        cin >> x >> y;
        list.push_back({x, y});
    }
    stable_sort(list.begin(), list.end(), [](const vector<int>& a, const vector<int>& b){
       if(a[0] == b[0]) return a[1] < b[1];
       else return a[0] < b[0];
    });
    for(int i = 0 ; i < list.size() ; i++){
        cout << list[i][0] << ' ' << list[i][1] << "\n";
    }
    return 0;
}
