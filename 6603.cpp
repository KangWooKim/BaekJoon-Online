// https://www.acmicpc.net/problem/6603

#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> s;
vector<int> val;

void dfs(int idx){
    if(val.size() == 6){
        for(auto& v : val){
            cout << v << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i = idx + 1 ; i < s.size() ; i++){
        val.push_back(s[i]);
        int tmp = idx; idx = i;
        dfs(idx);
        idx = tmp; val.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin >> k;
        if(k == 0) break;
        s = vector<int>(k);
        for(int i = 0 ; i < k ; i++)
            cin >> s[i];
        val.clear();
        dfs(-1);
        cout << "\n";
    }
    
    return 0;
}
