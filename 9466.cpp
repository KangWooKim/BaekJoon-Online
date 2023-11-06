// https://www.acmicpc.net/problem/9466

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 전역 변수로 방문 상태를 저장할 배열을 선언합니다.
const int MAX = 100001;
int student[MAX];
bool visited[MAX];
bool finished[MAX];
int cnt; // 프로젝트 팀에 속하지 않은 학생들의 수

void dfs(int now) {
    visited[now] = true;
    int next = student[now];

    if (!visited[next]) {
        dfs(next);
    } else {
        // 이미 방문했지만 사이클이 끝나지 않은 노드라면 사이클에 포함된다는 의미
        if (!finished[next]) {
            // 사이클에 포함된 노드 수만큼 카운트를 줄입니다.
            for (int i = next; i != now; i = student[i]) {
                cnt++;
            }
            cnt++; // 사이클을 형성하는 마지막 노드를 추가
        }
    }
    // 현재 노드에 대한 처리가 끝났음을 표시합니다.
    finished[now] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n;
    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> student[i];
        }

        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        cnt = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) dfs(i);
        }

        // 전체 학생 수에서 사이클에 포함된 학생의 수를 빼서
        // 팀에 속하지 않은 학생의 수를 구합니다.
        cout << n - cnt << '\n';
    }

    return 0;
}
