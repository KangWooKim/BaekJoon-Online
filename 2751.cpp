// https://www.acmicpc.net/problem/2751

#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int N;
    cin >> N;
    while(N--){
        int a;
        cin >> a;
        pq.push(a);
    }
    while(!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
    }
    return 0;
}
