// https://www.acmicpc.net/problem/15649

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
vector<int> l;

void dfs(vector<int>& list){
    if(list.size() == m){
        for(auto& l : list){
            cout << l << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i = 1 ; i <= n ; i++){
        if(v[i] == 1){
            list.push_back(i);
            v[i]--;
            dfs(list);
            list.pop_back();
            v[i]++;
        }
    }
}

int main(){
    cin >> n >> m;
    v = vector<int>(n + 1, 1);
    
    dfs(l);
    return 0;
}
