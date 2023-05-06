// https://www.acmicpc.net/problem/2164

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> q;
    int i;
    cin >> i;
    for(int j = 1 ; j <= i ; j++)
        q.push(j);
    while(q.size() != 1){
        q.pop();
        int k = q.front();
        q.pop();
        q.push(k);
    }
    cout << q.front();
    return 0;
}
