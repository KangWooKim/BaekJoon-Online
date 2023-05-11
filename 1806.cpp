// https://www.acmicpc.net/problem/1806

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int start = 0; int end = 0;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    int sum = v[0]; int answer = v.size() + 1;
    while(start <= end && end < n && start < n){
        if(start == end && sum == s) {answer = 1; break;}
        if(sum < s){sum += v[++end];}
        else if(sum >= s){answer = min(answer, end - start + 1); sum -= v[start++];}
    }
    if(answer == v.size() + 1) cout << 0;
    else cout << answer;
    return 0;
}
