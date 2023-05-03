// https://www.acmicpc.net/problem/20040

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

bool union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return false;
    }
    parent[y] = x;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    int cycle_turn = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;

        if (!union_set(x, y)) {
            cycle_turn = i;
            break;
        }
    }

    cout << cycle_turn << endl;
    return 0;
}
