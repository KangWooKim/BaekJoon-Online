// https://www.acmicpc.net/problem/1074

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; long long r, c;
    if (!(cin >> N >> r >> c)) return 0;

    long long ans = 0;
    long long len = 1LL << N; // 현재 정사각형 한 변 길이

    while (len > 1) {
        long long half = len >> 1;     // 사분면 크기
        long long quad = 0;            // 사분면 번호: 0,1,2,3

        if (r < half && c < half) {
            quad = 0;                  // 좌상
        } else if (r < half && c >= half) {
            quad = 1;                  // 우상
            c -= half;
        } else if (r >= half && c < half) {
            quad = 2;                  // 좌하
            r -= half;
        } else {
            quad = 3;                  // 우하
            r -= half; c -= half;
        }

        ans += quad * (half * half);   // 이전 사분면들 크기만큼 더하기
        len = half;                    // 더 작은 정사각형으로 이동
    }

    cout << ans << '\n';
    return 0;
}
