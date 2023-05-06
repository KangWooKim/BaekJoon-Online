// https://www.acmicpc.net/problem/10828

#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void custom_pop(){
    if(v.size() == 0){cout << -1 << "\n"; return;}
    cout << v.back() << "\n";
    v.pop_back();
    return;
}

void custom_size(){
    cout << v.size() << "\n";
    return;
}

void custom_empty(){
    if(v.size() == 0) cout << 1 << "\n";
    else cout << 0 << "\n";
    return;
}

void custom_top(){
    if(v.size() == 0){cout << -1 << "\n"; return;}
    cout << v.back() << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;
    
    while(TC--){
        string order;
        cin >> order;
        int i;
        if(order == "push") {cin >> i; v.push_back(i);}
        else if(order == "top") custom_top();
        else if(order == "pop") custom_pop();
        else if(order == "empty") custom_empty();
        else if(order == "size") custom_size();
    }
    return 0;
}
