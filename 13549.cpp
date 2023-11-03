//https://www.acmicpc.net/problem/13549

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<bool> visited(100001, false);
vector<int> second(100001, INT_MAX); 

void bfs() {
    second[N] = 0;
    visited[N] = true;
    queue<int> q;
    q.push(N);

    while(!q.empty()) {
        int current_position = q.front();
        q.pop();

        // 순간이동
        if(current_position * 2 < 100001 && !visited[current_position * 2]) {
            visited[current_position * 2] = true;
            second[current_position * 2] = second[current_position];
            q.push(current_position * 2);
        }

        
        // 걷기 (뒤로)
        if(current_position - 1 >= 0 && !visited[current_position - 1]) {
            visited[current_position - 1] = true;
            second[current_position - 1] = second[current_position] + 1;
            q.push(current_position - 1);
        }
        
        // 걷기 (앞으로)
        if(current_position + 1 < 100001 && !visited[current_position + 1]) {
            visited[current_position + 1] = true;
            second[current_position + 1] = second[current_position] + 1;
            q.push(current_position + 1);
        }
        
        

    }
}

int main() {
    cin >> N >> K;
    bfs();
    cout << second[K]; // 동생을 찾는 데 걸리는 최소 시간 출력
    return 0;
}
