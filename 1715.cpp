// https://www.acmicpc.net/problem/1715

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq; // greater<int>로 수정하여 오름차순으로 정렬되게 함
    while(n--){
        int a; cin >> a;
        pq.push(a);
    }
    int sum = 0;
    while(pq.size() > 1){  // 우선 순위 큐에 항목이 두 개 이상 남아있는 경우에만 수행
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        sum += first + second;
        pq.push(first + second);
    }
    cout << sum;
    return 0;
}
