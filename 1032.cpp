// https://www.acmicpc.net/problem/1032

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string pat;
    cin >> pat; // 첫 문자열을 초기 패턴으로 사용

    for (int k = 1; k < n; ++k) {
        string s;
        cin >> s;
        for (size_t i = 0; i < pat.size(); ++i) {
            if (pat[i] != s[i]) pat[i] = '?';
        }
    }

    cout << pat << '\n';
    return 0;
}
