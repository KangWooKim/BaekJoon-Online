// https://www.acmicpc.net/problem/1937

#include <iostream>
#include <vector>
#define MAX 501

using namespace std;

int forest[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (forest[nx][ny] > forest[x][y]) 
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> forest[i][j];
    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result = max(result, dfs(i, j));
    cout << result;
    return 0;
}
