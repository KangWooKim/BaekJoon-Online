// https://www.acmicpc.net/problem/2161

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> q;

    // 초기에 1부터 N까지 큐에 넣는다.
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (q.size() > 1) { // 카드가 한 장 남을 때까지
        // 제일 위의 카드를 버린다.
        cout << q.front() << " ";
        q.pop();

        // 그 다음 카드를 제일 아래로 옮긴다.
        int nextCard = q.front();
        q.pop();
        q.push(nextCard);
    }

    // 마지막에 남은 카드를 출력한다.
    cout << q.front() << endl;

    return 0;
}
