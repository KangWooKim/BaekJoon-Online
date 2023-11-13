// https://www.acmicpc.net/problem/11286

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

// 우선순위 큐를 위한 사용자 정의 비교 함수
struct compare {
    bool operator()(int a, int b) {
        int absA = abs(a), absB = abs(b);
        if (absA == absB) return a > b;
        return absA > absB;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x;
    cin >> N;

    priority_queue<int, vector<int>, compare> pq;

    while (N--) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}
