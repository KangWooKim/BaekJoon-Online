// https://www.acmicpc.net/problem/1753

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;


int main(){
    int V, E, K;
    cin >> V >> E;
    vector<pair<int, int>>graph[(V + 1)];
    vector<int>d(V + 1, INF);
    cin >> K;
    for(int i = 0 ; i < E ; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, K});
    d[K] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now= pq.top().second;
        pq.pop();
        
        if(d[now] < dist)continue;
        for(int i = 0 ; i < graph[now].size() ; i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
    
    for(int i = 1 ; i <= V ; i++){
        if(d[i] == INF) cout <<"INF" << '\n';
        else cout << d[i] << '\n';
    }
    
    
    return 0;
}
