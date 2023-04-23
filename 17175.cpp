// https://www.acmicpc.net/problem/17175

#include <bits/stdc++.h>
#define val 1000000007;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> answer(51, 0);
    answer[0] = 1; answer[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        answer[i] =1 + (answer[i - 2] + answer[i - 1]) % val;
    }
    cout << answer[n];
    return 0;
}
