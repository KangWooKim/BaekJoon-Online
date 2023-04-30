// https://www.acmicpc.net/problem/1012

#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool InRange(const int x, const int y, const int raw, const int col){
    bool b = x >= 0 && y >= 0 && x < raw && y < col;
    return b;
}

int main(){
    int TestCase;
    cin >> TestCase;
    while(TestCase--){
        int raw, col, cab; int answer = 0;
        cin >> raw >> col >> cab;
        vector<vector<int>> map(col, vector<int>(raw, 0));
        while(cab--){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        vector<vector<bool>> IsVisited(col, vector<bool>(raw, false));
        for(int y = 0 ; y < map.size() ; y++){
            for(int x = 0 ; x < map[y].size() ; x++){
                if(!IsVisited[y][x] && map[y][x] == 1){
                    ++answer;
                    IsVisited[y][x] = true;
                    queue<pair<int, int>> q;
                    q.push(make_pair(y, x));
                    while(!q.empty()){
                        int now_x = q.front().second;
                        int now_y = q.front().first;
                        q.pop();
                        for(int i = 0 ; i < 4 ; i++){
                            int nx = now_x + dx[i]; int ny = now_y + dy[i];
                            if(InRange(nx, ny, raw, col) && map[ny][nx] == 1 && !IsVisited[ny][nx]){
                                IsVisited[ny][nx] = true;
                                q.push(make_pair(ny, nx));
                            }
                        }
                    }
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
