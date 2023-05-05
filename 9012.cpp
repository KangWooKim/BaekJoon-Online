// https://www.acmicpc.net/problem/9012

#include <bits/stdc++.h>
using namespace std;

void printing(bool b){
    if(b){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;
    while(TC--){
        string ps;
        cin >> ps;
        int cnt = 0; bool crt = true;
        for(int i = 0 ; i < ps.length() ; i++){
            if(ps[i] == '(') ++cnt;
            else if(ps[i] == ')') --cnt;
            if(cnt < 0) {crt = false; break;}
        }
        if(cnt != 0) crt = false;
        printing(crt);
    }
    return 0;
}
