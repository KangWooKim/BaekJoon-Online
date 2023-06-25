// https://www.acmicpc.net/problem/16234

#include <bits/stdc++.h>
using namespace std;
int N, L, R;
int answer = 0;
vector<vector<int>> world;
vector<vector<pair<int, int>>> v;
vector<vector<bool>> visited;
vector<int> nx = {-1, 1, 0, 0};
vector<int> ny = {0, 0, -1, 1};

bool InRange(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}

void make_union(int x, int y){
    vector<pair<int, int>> temp;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    temp.push_back({x, y});
    while(!q.empty()){
        int a = q.front().first; int b = q.front().second; q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int xx = a + nx[i]; int yy = b + ny[i];
            if(!InRange(xx, yy) || visited[xx][yy]) continue;
            int diff = abs(world[a][b] - world[xx][yy]);
            if(diff < L || diff > R) continue;
            visited[xx][yy] = true;
            q.push({xx, yy});
            temp.push_back({xx, yy});
        }
    }
    if(temp.size() > 1) v.push_back(temp);
    return;
}

void move_people(){
    for(auto& u : v){
        int people = 0;
        for(auto& c : u){
            people += world[c.first][c.second];
        }
        people /= u.size();
        for(auto& c: u){
            world[c.first][c.second] = people;
        }
    }
    return;
}

int main(){
    cin >> N >> L >> R;
    world = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> world[i][j];
    while(true){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(!visited[i][j]) make_union(i, j);
            }
        }
        if(v.empty()){cout << answer; return 0;}
        move_people();
        visited = vector<vector<bool>>(N, vector<bool>(N, false));
        v.clear();
        ++answer;
    }
    return 0;
}
