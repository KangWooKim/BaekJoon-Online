// https://www.acmicpc.net/problem/1463

#include <bits/stdc++.h>
#define FastFC cin.tie(NULL),cout.tie(NULL),ios::sync_with_stdio(false)
using namespace std;

int main(){
    FastFC;
    long long N;
    cin >> N;
    if(N == 1){
        cout << 0;
        return 0;
    }
    vector<int> answer(N + 1, 987654321);
    answer[2] = 1; answer[3] = 1;
    for(int i = 4 ; i < answer.size() ; i++){
        if(i % 3 == 0){
            int res = answer[i / 3] + 1;
            answer[i] = min(answer[i], res);
        }
        if(i % 2 == 0){
            int res = answer[i / 2] + 1;
            answer[i] = min(answer[i], res);
        }
        int res = answer[i - 1] + 1;
        answer[i] = min(answer[i], res);
    }
    cout << answer[N];
    return 0;
}
