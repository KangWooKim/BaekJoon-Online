// https://www.acmicpc.net/problem/1759

#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> v;
string s = "";

bool checking_aeiou(char a) {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void dfs(bool has_aeiou, int cnt, int idx) {
    if (s.length() == l && has_aeiou && cnt >= 2) {
        cout << s << "\n";
        return;
    }
    for (int i = idx; i < v.size(); i++) {
        s += v[i];
        if (!checking_aeiou(v[i]))
            dfs(has_aeiou, cnt + 1, i + 1); // 다음 인덱스부터 탐색
        else
            dfs(true, cnt, i + 1); // 모음이면 cnt는 증가하지 않음
        s.pop_back();
    }
    return;
}

int main() {
    cin >> l >> c;
    v = vector<char>(c);
    for (int i = 0; i < c; i++) {
        cin >> v[i];
    }
    stable_sort(v.begin(), v.end());
    dfs(false, 0, 0); // 인덱스 0부터 시작
    return 0;
}
