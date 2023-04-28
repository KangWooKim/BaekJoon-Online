// https://www.acmicpc.net/problem/1025

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<string> A;
int ans = -1;

bool is_square(int x) {
    int root = static_cast<int>(sqrt(x));
    return root * root == x;
}

void dfs(int x, int y, int num, int diff_x, int diff_y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    num = num * 10 + (A[x][y] - '0');
    if (is_square(num)) ans = max(ans, num);

    dfs(x + diff_x, y + diff_y, num, diff_x, diff_y);
}

int main() {
    cin >> N >> M;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int diff_x = -N; diff_x <= N; ++diff_x) {
                for (int diff_y = -M; diff_y <= M; ++diff_y) {
                    if (diff_x == 0 && diff_y == 0) continue;
                    dfs(i, j, 0, diff_x, diff_y);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
