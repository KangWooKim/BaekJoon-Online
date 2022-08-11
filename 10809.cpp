// https://www.acmicpc.net/problem/10809

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(char c1 = 'a' ; c1 != 'z' + 1 ; c1++){
        if(find(s.begin(), s.end(), c1) == s.end())
            cout << -1 << ' ';
        else{
            int idx = find(s.begin(), s.end(), c1) - s.begin();
            cout << idx << ' ';
        }
    }
    return 0;
}
