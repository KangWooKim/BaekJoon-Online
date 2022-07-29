// https://www.acmicpc.net/problem/11720

#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt;
    cin >> cnt;
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0 ; i < cnt ; i++){
        string s1 = s.substr(i, 1);
        int x = stoi(s1);
        sum += x;
    }
    cout << sum;
    return 0;
}
