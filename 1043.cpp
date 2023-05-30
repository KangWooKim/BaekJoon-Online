// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> truth;
vector<int> parent;
vector<vector<int>> party;
int N, M;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int truthNum;
    cin >> N >> M >> truthNum;

    truth.resize(truthNum);
    parent.resize(N + 1);
    party.resize(M + 1);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < truthNum; i++) {
        cin >> truth[i];
    }

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        party[i].resize(num);

        for (int j = 0; j < num; j++) {
            cin >> party[i][j];

            if (j > 0) 
                unionParent(party[i][j - 1], party[i][j]);
        }
    }

    for (int i = 1; i < truthNum; i++) 
        unionParent(truth[i - 1], truth[i]);

    int answer = 0;
    for (int i = 0; i < M; i++) {
        bool flag = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (!flag) break;

            for (int k = 0; k < truthNum; k++) {
                if (getParent(party[i][j]) == getParent(truth[k])) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) answer++;
    }
    cout << answer;

    return 0;
}
