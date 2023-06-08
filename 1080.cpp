// https://www.acmicpc.net/problem/1080

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> A, B;

void flip(int y, int x) {
    for (int i = y; i < y + 3; ++i) {
        for (int j = x; j < x + 3; ++j) {
            A[i][j] = 1 - A[i][j];
        }
    }
}

int main() {
    cin >> N >> M;
    A = vector<vector<int>>(N, vector<int>(M));
    B = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            A[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            B[i][j] = s[j] - '0';
        }
    }

    int count = 0;
    for (int i = 0; i <= N - 3; ++i) {
        for (int j = 0; j <= M - 3; ++j) {
            if (A[i][j] != B[i][j]) {
                flip(i, j);
                ++count;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (A[i][j] != B[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << count;
    return 0;
}
