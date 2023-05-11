// https://www.acmicpc.net/problem/10026

#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> picture;
vector<vector<bool>> p1;
vector<vector<bool>> p2;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool InRange(int x, int y){
    return x >= 0 && x < n ; y >= 0 && y < n;
}

void dfs1(int x, int y){
    if(!InRange(x, y)) return;
    p1[x][y] = true; char c = picture[x][y];
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i]; int ny = y + dy[i];
        if(InRange(nx, ny) && !p1[nx][ny] && picture[nx][ny] == c) dfs1(nx, ny);
    }
}

void dfs2(int x, int y){
    if(!InRange(x, y)) return;
    p2[x][y] = true; char c = picture[x][y];
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i]; int ny = y + dy[i];
        if(InRange(nx, ny) && !p2[nx][ny] && 
           (((c == 'R' || c == 'G') && (picture[nx][ny] == 'R' || picture[nx][ny] == 'G')) ||
           c == 'B' && picture[nx][ny] == 'B')
          ) 
            dfs2(nx, ny);
    }
}

int main(){
    cin >> n;
    picture = vector<string>(n);
    for(int i = 0 ; i < n ; i++)
        cin >> picture[i];
    p1 = vector<vector<bool>>(n, vector<bool>(n, false));
    p2 = vector<vector<bool>>(n, vector<bool>(n, false));
    int answer1 = 0; int answer2 = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            if(!p1[i][j]){answer1++; dfs1(i, j);}
            if(!p2[i][j]){answer2++; dfs2(i, j);}
        }
    }
    cout << answer1 << ' ' << answer2;
    return 0;
}
