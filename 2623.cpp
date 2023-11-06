// https://www.acmicpc.net/problem/2623

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> indegree(N + 1, 0); // 모든 가수의 진입 차수를 0으로 초기화
    vector<vector<int>> graph(N + 1); // 가수들의 관계를 나타내는 그래프
    queue<int> Q; // 진입 차수가 0인 노드를 담을 큐
    
    // 보조 PD가 정한 순서를 그래프로 표현하며 진입 차수를 업데이트
    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        vector<int> order(k);
        for (int j = 0; j < k; ++j) {
            cin >> order[j];
        }
        for (int j = 1; j < k; ++j) {
            graph[order[j - 1]].push_back(order[j]);
            indegree[order[j]]++;
        }
    }
    
    // 진입 차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }
    
    // 위상 정렬 결과를 담을 벡터
    vector<int> result;
    
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        result.push_back(current);
        
        // 현재 노드와 연결된 노드의 진입 차수를 1 줄임
        for (int next : graph[current]) {
            indegree[next]--;
            // 새롭게 진입 차수가 0이 된 노드를 큐에 삽입
            if (indegree[next] == 0) {
                Q.push(next);
            }
        }
    }
    
    // 모든 가수가 위상 정렬 결과에 포함되지 않았다면 순서를 정하는 것이 불가능한 것
    if (result.size() != N) {
        cout << 0 << endl;
    } else {
        // 가능한 한 순서대로 출력
        for (int i : result) {
            cout << i << endl;
        }
    }
    
    return 0;
}
