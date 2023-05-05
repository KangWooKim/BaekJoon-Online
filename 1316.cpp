// https://www.acmicpc.net/problem/1316

#include <bits/stdc++.h>
using namespace std;

bool GroupWordChecker(const string& s){
    if(s.length() == 1) return true;
    unordered_map<char, int> mp;
    mp[s[0]]++;
    for(int i = 1 ; i < s.length() ; i++){
        if(s[i] == s[i - 1]) continue;
        else if(s[i] != s[i - 1] && mp[s[i]] != 0) return false;
        else if(s[i] != s[i - 1]) mp[s[i]]++;
    }
    return true;
}

int main(){
    int TestCase, answer = 0;
    cin >> TestCase;
    while(TestCase--){
        string word;
        cin >> word;
        if(GroupWordChecker(word)) ++answer;
    }
    cout << answer;
    return 0;
}
