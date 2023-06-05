// https://www.acmicpc.net/problem/11403

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> answer;
vector<vector<int>> graph;

void FindPath(){
    for(int i = 0 ; i < n ; i++){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int k = 0 ; k < n ; k++){
                if(graph[now][k] == 0 || answer[i][k] == 1) continue;
                answer[i][k] = 1; q.push(k);
            }
        }
    }
}

void PrintAnswer(){
    for(auto& v : answer){
        for(auto& i : v){
            cout << i << ' ';
        }
        cout << "\n";
    }
}

int main(){
    cin >> n;
    graph = vector<vector<int>>(n, vector<int>(n, 0));
    answer = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> graph[i][j];
        }
    }
    FindPath();
    PrintAnswer();
    return 0;
}
