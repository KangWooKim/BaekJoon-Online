// https://www.acmicpc.net/problem/1339

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> wordList(N);
    vector<int> alphaValue(26, 0); // 알파벳별 가치 저장

    for(int i = 0; i < N; ++i){
        cin >> wordList[i];
        int len = wordList[i].length();
        for(int j = 0; j < len; ++j){
            // 10의 제곱수 계산을 정수 연산으로 대체
            alphaValue[wordList[i][j] - 'A'] += pow(10, len - j - 1);
        }
    }
    
    // 정렬을 위한 쌍(pair)의 배열 대신 단순히 값 배열을 사용
    sort(alphaValue.rbegin(), alphaValue.rend()); // 내림차순 정렬

    int answer = 0;
    for(int i = 0; i < 10; ++i){
        // 상위 10개 알파벳에만 점수를 할당
        answer += alphaValue[i] * (9 - i);
    }

    cout << answer;
    return 0;
}
