// https://www.acmicpc.net/problem/11047

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> list;
    for(int i = 0 ; i < n ; i++){
        int money; cin >> money;
        list.push_back(money);
    }
    sort(list.rbegin(), list.rend());
    int answer = 0;
    for(auto money : list){
        if(k >= money){
            answer = answer + k / money;
            k = k - ((k / money) * money);
        }
        if(k == 0) break;
    }
    cout << answer;
    return 0;
}
