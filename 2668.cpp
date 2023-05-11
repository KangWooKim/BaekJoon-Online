// https://www.acmicpc.net/problem/2668

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> graph[101];
bool visited[101];
bool finished[101];
vector<int> result;

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            dfs(next);
        } else if (!finished[next]) {
            for (int start = next; start != node; start = graph[start][0]) {
                result.push_back(start);
            }
            result.push_back(node);
        }
    }
    finished[node] = true;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        graph[i].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
    return 0;
}
