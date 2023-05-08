// https://www.acmicpc.net/problem/1697

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v;

bool InRange(int x){
    return x >= 0 && x < v.size();
}

int main(){
    cin >> N >> K;
    v = vector<int>(300000, -1);
    queue<int> q;
    q.push(N); v[N] = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        vector<int> vv = {now - 1, now + 1, now * 2};
        for(int i = 0 ; i < vv.size() ; i++){
            if(!InRange(vv[i]) || v[vv[i]] != -1) continue;
            q.push(vv[i]); v[vv[i]] = v[now] + 1;
            if(vv[i] == K) break;
        }
    }
    cout << v[K];
    return 0;
}
