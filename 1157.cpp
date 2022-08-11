//https://www.acmicpc.net/problem/1157

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(auto& c : s)
        c = toupper(c);
    map<char, int> mp;
    for(auto& c : s){
        mp[c]++;
    }
    char max = 'A'; int cnt = 0;
    for(char c = 'A' ; c != 'Z' + 1 ; c++){
        if(mp[max] < mp[c]){max = c; cnt = 1;}
        else if(mp[max] == mp[c]){cnt++;}
    }
    if(cnt != 1) max = '?';
    cout << max;
    return 0;
}
