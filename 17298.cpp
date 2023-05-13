// https://www.acmicpc.net/problem/17298

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    vector<int> answer(n, -1);
    vector<int> vv; vv.push_back(v.back());
    for(int i = n - 2 ; i >= 0 ; i--){
        if(!vv.empty() && vv.back() <= v[i]){
            while(!vv.empty() && vv.back() <= v[i]){
                vv.pop_back();
            }
        }
        if(vv.empty()){
            vv.push_back(v[i]);
            continue;
        }
        if(!vv.empty() && vv.back() > v[i]){
            answer[i] = vv.back();
            vv.push_back(v[i]);
        }
    }
    for(int i = 0 ; i < answer.size() ; i++){
        cout << answer[i] << ' ';
    }
    return 0;
}
