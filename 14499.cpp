// https://www.acmicpc.net/submit/14499

#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, k;
vector<vector<int>> v;
vector<int> order;

int top = 0, bottom = 0;
int north = 0, south = 0, east = 0, west = 0;

void copyDice() {
    if (v[x][y] == 0) {
        v[x][y] = bottom;
    } else {
        bottom = v[x][y];
        v[x][y] = 0;
    }
}

int main() {
    cin >> N >> M >> x >> y >> k;
    v = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v[i][j];

    order.resize(k);
    for (int i = 0; i < k; i++)
        cin >> order[i];

    for (int i = 0; i < k; i++) {
        int o = order[i];
        if (o == 1) {
            if (y + 1 >= M) continue;
            y++;
            int temp = top;
            top = west; west = bottom; bottom = east; east = temp;
        } else if (o == 2) {
            if (y - 1 < 0) continue;
            y--;
            int temp = top;
            top = east; east = bottom; bottom = west; west = temp;
        } else if (o == 3) {
            if (x - 1 < 0) continue;
            x--;
            int temp = top;
            top = south; south = bottom; bottom = north; north = temp;
        } else if (o == 4) {
            if (x + 1 >= N) continue;
            x++;
            int temp = top;
            top = north; north = bottom; bottom = south; south = temp;
        }
        copyDice();
        cout << top << "\n";
    }
    return 0;
}
