// https://www.acmicpc.net/problem/10816

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<long long, int> card_count; // 숫자 카드 등장 횟수를 저장할 map
    
    for (int i = 0; i < N; ++i) {
        long long card;
        cin >> card;
        card_count[card]++; // 카드 등장 횟수 증가
    }

    int M;
    cin >> M;
    vector<long long> queries(M);
    
    for (int i = 0; i < M; ++i) {
        cin >> queries[i];
    }

    // 각 쿼리에 대해 등장 횟수 출력
    for (int i = 0; i < M; ++i) {
        cout << card_count[queries[i]] << " ";
    }
    cout << endl;

    return 0;
}
