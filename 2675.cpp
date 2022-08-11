//https://www.acmicpc.net/problem/2675

#include <bits/stdc++.h>
using namespace std;
int main(){
    int number;
    cin >> number;
    for(int i = 0 ; i < number ; i++){
        int n; string s;
        cin >> n >> s;
        for(int x = 0 ; x < s.length() ; x++){
            for(int y = 0 ; y < n ; y++){
                cout << s[x];
            }
        }
        cout << '\n';
    }
    return 0;
}
