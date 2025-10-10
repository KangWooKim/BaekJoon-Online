#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> board;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y, int mask, int len) {
    int best = len;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        int bit = 1 << (board[nx][ny] - 'A');
        if ((mask & bit) == 0) {
            best = max(best, dfs(nx, ny, mask | bit, len + 1));
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    board.resize(R);
    for (int i = 0; i < R; ++i) cin >> board[i];

    int startBit = 1 << (board[0][0] - 'A');
    cout << dfs(0, 0, startBit, 1) << "\n";
    return 0;
}
