// https://www.acmicpc.net/problem/6550

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; string t;
    while(cin >> s >> t){
        int index = 0;
        for(int i = 0 ; i < t.length() ; i++){
            if(index < s.length() && s[index] == t[i]){
                index++;
            }
            if(index == s.length()) break;
        }
        if(index == s.length()){
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    
    return 0;
}
