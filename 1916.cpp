// https://www.acmicpc.net/problem/1916

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<pair<int, int>> mp[1001];
vector<int> d;
int start, finish;

void dijkstra(){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist) continue;
        for(int i = 0 ; i < mp[now].size() ; i++){
            int cost = dist + mp[now][i].second;
            if(cost < d[mp[now][i].first]){
                d[mp[now][i].first] = cost;
                pq.push({-cost, mp[now][i].first});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    d = vector<int>(n + 1, INF);
    for(int i = 0 ; i < m ; i++){
        int s, e, dis; cin >> s >> e >> dis;
        mp[s].push_back({e, dis});
    }
    cin >> start >> finish;
    dijkstra();
    cout << d[finish];
    return 0;
}
