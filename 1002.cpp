// https://www.acmicpc.net/problem/1002

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        long long dx = x1 - x2;
        long long dy = y1 - y2;
        long long d2 = dx*dx + dy*dy;

        long long sum = r1 + r2;
        long long diff = llabs(r1 - r2);
        long long S2 = sum * sum;
        long long D2 = diff * diff;

        if (d2 == 0 && r1 == r2) {
            cout << -1 << '\n';
        } else if (d2 == S2 || d2 == D2) {
            cout << 1 << '\n';
        } else if (D2 < d2 && d2 < S2) {
            cout << 2 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
