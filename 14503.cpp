// https://www.acmicpc.net/problem/14503

#include<iostream>

using namespace std;

int N, M, r, c, d, cnt;
int map[50][50];
int check[50][50] = {0,};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool reverse() {
    int rd = (d+2)%4;
    int nx = r + dx[rd];
    int ny = c + dy[rd];
    
    if(map[nx][ny]==1) {
        return true;
    }
    else {
        r = nx;
        c = ny;
        return false;
    }
}

void dfs() {
    check[r][c] = 1;
    int cur_dir = d;
    for(int i = 0; i < 4; i++) {
        d = (d + 3) % 4;
        int nx = r + dx[d];
        int ny = c + dy[d];

        if(check[nx][ny] == 0 && map[nx][ny] == 0) {
            r = nx; c = ny;
            cnt++;
            dfs();
            break;
        }
    }
    
    if(cur_dir == d) {
        if(reverse()) 
            return;
        else 
            dfs();
    }
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    cnt = 1;
    dfs();
    
    cout << cnt << endl;

    return 0;
}
