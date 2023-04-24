// https://www.acmicpc.net/problem/1010

#include <bits/stdc++.h>
#define FastFC cin.tie(NULL),cout.tie(NULL),ios::sync_with_stdio(false)
using namespace std;

void ans(const int west, const int east){
    if(west == east) cout << 1;
    else{
        unsigned long long answer = 1;
        for(int i = 1 ; i <= west ; i++){
            answer *= (east - i + 1);
            answer /= i;
        }
        cout << answer;
    }
    cout << "\n";
    return;
}

int main(){
    FastFC;
    int cnt;
    cin >> cnt;
    for(int i = 0 ; i < cnt ; i++){
       int west; int east;
       cin >> west >> east;
       ans(west, east);
    }
    return 0;
}
