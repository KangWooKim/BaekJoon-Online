// https://www.acmicpc.net/problem/1065

#include <bits/stdc++.h>
using namespace std;

bool Is_Hansu(int a){
    if(a < 100) return true;
    string s = to_string(a);
    int diff = (s[1] - '0') - (s[0] - '0');
    for(int i = 2 ; i < s.length() ; i++){
        if((s[i] - '0') - (s[i - 1] - '0') != diff) return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    int answer = 0;
    for(int i = 1 ; i <= N ; i++){
        if(Is_Hansu(i)) ++answer;
    }
    cout << answer;
    return 0;
}
