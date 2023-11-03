// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long> tower(N);
    for(int i = 0; i < N; i++){
        cin >> tower[i];
    }

    stack<pair<int, long>> s;
    vector<int> answer(N, 0);

    // 탑들을 거꾸로 탐색하며 처리합니다.
    for(int i = 0; i < N; i++){
        // 스택이 비어있지 않고 현재 탑이 스택의 탑보다 클 때까지 스택에서 탑을 제거합니다.
        while(!s.empty() && s.top().second < tower[i]){
            s.pop();
        }
        // 스택이 비어있지 않다면 현재 탑의 신호를 수신할 탑이 스택의 top에 있습니다.
        if(!s.empty()){
            answer[i] = s.top().first + 1; // 인덱스는 0부터 시작하지만 문제에서는 1부터 시작하는 번호를 요구합니다.
        }
        // 현재 탑을 스택에 푸시합니다.
        s.push({i, tower[i]});
    }

    for(int i = 0; i < N; i++){
        cout << answer[i] << ' ';
    }
    return 0;
}
