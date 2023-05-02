// https://www.acmicpc.net/problem/7576

#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool InRange(int x, int y, int m, int n){
    bool R = x >= 0 && y >= 0 && y < n && x < m;
    return R;
}

int main(){
    int M, N;
    cin >> M >> N;
    vector<vector<int>> c(N, vector<int>(M, 0));
    vector<vector<int>> day(N, vector<int>(M, -1));
    queue<vector<int>> q;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> c[i][j];
            if(c[i][j] == 1) {
                day[i][j] = 0;
                q.push({i, j, 0}); // 익은 토마토의 위치를 큐에 추가
            }
        }
    }
    
    while(!q.empty()){
        int now_x = q.front()[1]; int now_y = q.front()[0]; int d = q.front()[2];
        q.pop();
        for(int k = 0 ; k < dx.size() ; k++){
            int nx = now_x + dx[k]; int ny = now_y + dy[k];
            if(!InRange(nx, ny, M, N)) continue;
            if(c[ny][nx] == 1 || c[ny][nx] == -1) continue;
            if(c[ny][nx] == 0 && (day[ny][nx] == -1 || day[ny][nx] > d + 1)){
                q.push({ny, nx, d + 1});
                day[ny][nx] = d + 1;
            }
        }
    }
    
    int answer = 0;
    for(int y = 0 ; y < c.size() ; y++){
        for(int x = 0 ; x < c[y].size() ; x++){
            if(c[y][x] == 0 && day[y][x] == -1){
                cout << -1;
                return 0;
            }
            if(c[y][x] == 0 && day[y][x] != -1){
                answer = max(answer, day[y][x]);
            }
        }
    }
    cout << answer;
    return 0;
}
