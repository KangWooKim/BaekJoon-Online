// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool isValid(int x, int y, int l) {
    return x >= 0 && y >= 0 && x < l && y < l;
}

int minKnightMoves(int l, pair<int, int> start, pair<int, int> end) {
    vector<vector<int>> dist(l, vector<int>(l, -1));
    dist[start.first][start.second] = 0;

    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == end.first && y == end.second) {
            return dist[x][y];
        }

        for (auto move : moves) {
            int nx = x + move.first;
            int ny = y + move.second;

            if (isValid(nx, ny, l) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int l;
        cin >> l;

        pair<int, int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        cout << minKnightMoves(l, start, end) << endl;
    }

    return 0;
}
