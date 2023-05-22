// https://www.acmicpc.net/problem/15650

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> number;
vector<int> l;

void dfs(int last){
    if(l.size() == m){
        for(auto& a : l){
            cout << a << ' ';
        }
        cout << "\n";
        return;
    }
    
    if(last == n && l.size() != m) return;
    
    for(int i = last + 1 ; i <= n ; i++){
        if(number[i] == 1){
            number[i]--;
            l.push_back(i);
            dfs(i);
            number[i]++;
            l.pop_back();
        }
    }
}

int main(){
    cin >> n >> m;
    number = vector<int>(n + 1, 1);
    dfs(0);
    return 0;
}
