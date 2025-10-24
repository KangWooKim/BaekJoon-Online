// https://www.acmicpc.net/problem/1253

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int good = 0;
    for (int i = 0; i < N; ++i) {
        long long target = a[i];
        int l = 0, r = N - 1;
        bool ok = false;

        while (l < r) {
            if (l == i) { ++l; continue; }
            if (r == i) { --r; continue; }

            long long s = a[l] + a[r];
            if (s == target) { ok = true; break; }
            else if (s < target) ++l;
            else --r;
        }

        if (ok) ++good;
    }

    cout << good << '\n';
    return 0;
}
