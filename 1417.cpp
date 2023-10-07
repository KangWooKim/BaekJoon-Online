// https://www.acmicpc.net/problem/1417

#include <bits/stdc++.h>
using namespace std;

int main(){
    int people;
    cin >> people;
    int DS;
    cin >> DS;
    priority_queue<int, vector<int>, less<int>> votes;
    for(int i = 0 ; i < people - 1 ; i++){
        int v; cin >> v;
        votes.push(v);
    }
    int answer = 0;
    while(!votes.empty() && DS <= votes.top()){
        int v = votes.top();
        votes.pop();
        --v;
        ++DS;
        votes.push(v);
        ++answer;
    }
    cout << answer;
    
    return 0;
}
