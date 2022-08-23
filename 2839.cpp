// https://www.acmicpc.net/problem/2839

#include <bits/stdc++.h>
using namespace std;
int main(){
    int five = 0; int three = 0; int kilo;
    cin >> kilo;
    if(kilo % 5 == 0){cout << kilo / 5; return 0;}
    five = (kilo + 5) / 5;
    while(five != 0){
        int sum = five * 5 + three * 3;
        if(sum == kilo){cout << five + three; return 0;}
        if(sum > kilo){--five; three = 0; continue;}
        if(sum < kilo){++three; continue;}
    }
    if(kilo % 3 == 0){cout << kilo / 3; return 0;}
    else cout << -1;
    return 0;
}
