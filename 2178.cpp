// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> maze;
vector<vector<bool>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && maze[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, cnt + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;
    maze = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    cout << bfs() << endl;

    return 0;
}
