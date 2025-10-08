// https://www.acmicpc.net/problem/7569

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, H;                // M: 가로(열), N: 세로(행), H: 높이(층)
    if (!(cin >> M >> N >> H)) return 0;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(N, vector<int>(M, -1)));
    queue<tuple<int,int,int>> q; // (z, x, y) = (층, 행, 열)

    for (int z = 0; z < H; ++z) {
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < M; ++y) {
                cin >> box[z][x][y];
                if (box[z][x][y] == 1) {
                    q.emplace(z, x, y);
                    dist[z][x][y] = 0; // 시작점의 날짜 = 0
                }
            }
        }
    }

    int dz[6] = { 0, 0, 0, 0,  1, -1 };
    int dx[6] = { 1,-1, 0, 0,  0,  0 };
    int dy[6] = { 0, 0, 1,-1,  0,  0 };

    while (!q.empty()) {
        auto [z, x, y] = q.front(); q.pop();
        for (int d = 0; d < 6; ++d) {
            int nz = z + dz[d], nx = x + dx[d], ny = y + dy[d];
            if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (box[nz][nx][ny] == 0) {
                box[nz][nx][ny] = 1;
                dist[nz][nx][ny] = dist[z][x][y] + 1;
                q.emplace(nz, nx, ny);
            }
        }
    }

    int ans = 0;
    for (int z = 0; z < H; ++z)
        for (int x = 0; x < N; ++x)
            for (int y = 0; y < M; ++y) {
                if (box[z][x][y] == 0) { cout << -1; return 0; } // 아직 안 익은 토마토 존재
                ans = max(ans, dist[z][x][y]);
            }
    cout << ans;
    return 0;
}
