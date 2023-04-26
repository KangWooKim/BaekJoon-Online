// https://www.acmicpc.net/problem/1052

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N, K;
    cin >> N >> K;

    int answer = 0;
    while (true) {
        int temp = N;
        int cnt = 0;
        while (temp) {
            cnt += temp % 2;
            temp /= 2;
        }

        if (cnt <= K) break;
        answer++;
        N++;
    }

    cout << answer << endl;
    return 0;
}
