// https://www.acmicpc.net/problem/1922

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선을 표현하는 구조체
struct Edge {
    int node1;
    int node2;
    int cost;
};

// 부모 노드를 찾는 함수
int findParent(vector<int>& parent, int node) {
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

// 두 노드를 연결하는 함수
void unionNodes(vector<int>& parent, int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    // 간선을 비용에 따라 오름차순으로 정렬
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.cost < b.cost;
    });

    // 각 정점의 부모를 자기 자신으로 초기화
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    for (Edge& edge : edges) {
        // 사이클이 형성되지 않으면 간선을 선택
        if (findParent(parent, edge.node1) != findParent(parent, edge.node2)) {
            unionNodes(parent, edge.node1, edge.node2);
            totalCost += edge.cost;
        }
    }

    cout << totalCost << endl;

    return 0;
}
