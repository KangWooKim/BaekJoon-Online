// https://www.acmicpc.net/problem/2467

#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;

int main(){
    cin >> n;
    v = vector<long long>(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    int l = 0; int r = n - 1; long long val = 2000000000;
    vector<int> answer(2, 0);
    while(l < r){
        long long res = v[l] + v[r];
        if(abs(res) < val){
            answer[0] = v[l]; answer[1] = v[r];
            val = abs(res);
        }
        if(res <= 0){
            ++l;
        }
        else if(res > 0){
            --r;
        }
    }
    cout << answer[0] << ' ' << answer[1];
    return 0;
}
