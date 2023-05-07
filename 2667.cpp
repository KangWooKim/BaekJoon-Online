// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> house_count;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    visited[x][y] = true;
    int count = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && map[nx][ny] == 1) {
            count += dfs(nx, ny);
        }
    }

    return count;
}

int main() {
    cin >> n;
    map = vector<vector<int>>(n, vector<int>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                house_count.push_back(dfs(i, j));
            }
        }
    }

    sort(house_count.begin(), house_count.end());
    cout << house_count.size() << endl;
    for (int count : house_count) {
        cout << count << endl;
    }

    return 0;
}
