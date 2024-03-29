// https://www.acmicpc.net/problem/1717

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 0; i <= n; ++i) parent[i] = i;

    for (int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) {
            union_sets(a, b);
        } else {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
