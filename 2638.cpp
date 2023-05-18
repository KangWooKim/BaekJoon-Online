// https://www.acmicpc.net/problem/2638

#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> visited;
vector<vector<int>> cheese;
vector<vector<int>> air;
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool InRange(const int& x, const int& y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

void ResetVector(){
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    air = vector<vector<int>>(n, vector<int>(m, 0));
}

bool Meltdown(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(cheese[i][j] == 1) return false;
        }
    }
    return true;
}

void Melt(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(cheese[i][j] == 1 && air[i][j] >= 2) cheese[i][j] = 0; 
        }
    }
}

int main(){
    int answer = 0;
    cin >> n >> m;
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    air = vector<vector<int>>(n, vector<int>(m, 0));
    cheese = vector<vector<int>>(n, vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> cheese[i][j];
        }
    }
    while(!Meltdown()){
        ResetVector();
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        while(!q.empty()){
            int x = q.front().first; int y = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i]; int ny = y + dy[i];
                if(!InRange(nx, ny)) continue;
                if(cheese[nx][ny] == 1) ++air[nx][ny];
                if(!visited[nx][ny] && cheese[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        Melt();
        ++answer;
    }
    cout << answer;
    return 0;
}
