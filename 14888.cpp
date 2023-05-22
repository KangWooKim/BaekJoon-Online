// https://www.acmicpc.net/problem/14888

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> numbers;
vector<int> operators;
long long maxResult = -1e9;
long long minResult = 1e9;

void dfs(int idx, long long sum) {
    if (idx == n) {
        maxResult = max(maxResult, sum);
        minResult = min(minResult, sum);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (operators[i] > 0) {
            operators[i]--;
            if (i == 0) dfs(idx + 1, sum + numbers[idx]);
            else if (i == 1) dfs(idx + 1, sum - numbers[idx]);
            else if (i == 2) dfs(idx + 1, sum * numbers[idx]);
            else dfs(idx + 1, sum / numbers[idx]);
            operators[i]++;
        }
    }
}

int main() {
    cin >> n;
    numbers.resize(n);
    operators.resize(4);
    for (int i = 0; i < n; ++i) cin >> numbers[i];
    for (int i = 0; i < 4; ++i) cin >> operators[i];
    dfs(1, numbers[0]);
    cout << maxResult << "\n" << minResult << "\n";
    return 0;
}
