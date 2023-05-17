// https://www.acmicpc.net/problem/11404

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n, m;
int graph[101][101];

void settingGraph(){
    for(int i = 0 ; i < 101 ; i++){
        fill(graph[i], graph[i] + 101, INF);
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j) graph[i][j] = 0;
        }
    }
}

void printAnswer(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int dis;
            if(i == j || graph[i][j] == 1e9) dis = 0;
            else dis = graph[i][j];
            cout << dis << ' ';
        }
        cout << "\n";
    }
}
int main(){
    cin >> n; cin >> m;
    settingGraph();
    while(m--){
        int st, ed, dis;
        cin >> st >> ed >> dis;
        graph[st][ed] = min(graph[st][ed], dis);
    }
    for(int k = 1 ; k <= n ; k++){
        for(int a = 1 ; a <= n ; a++){
            for(int b = 1 ; b <= n ; b++){
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
    printAnswer();
    return 0;
}
