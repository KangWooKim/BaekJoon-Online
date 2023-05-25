// https://www.acmicpc.net/problem/15663

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
vector<bool> ex;
vector<int> tmp;
set<vector<int>> st;

void printing(){
    if(!tmp.empty()){
        for(auto& t : tmp){
            cout << t << ' ';
        }
        cout << "\n";
    }
    st.insert(tmp);
    return;
}

void dfs(){
    if(tmp.size() == m && st.count(tmp) == 0){
        printing();
        return;
    }
    for(int i = 0 ; i < v.size() ; i++){
        if(ex[i]){
            ex[i] = false;
            tmp.push_back(v[i]);
            dfs();
            ex[i] = true;
            tmp.pop_back();
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    v = vector<int>(n);
    ex = vector<bool>(n, true);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    stable_sort(v.begin(), v.end());
    dfs();
    return 0;
}
