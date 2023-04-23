// https://www.acmicpc.net/problem/1629

#include <bits/stdc++.h>
using namespace std;

long long answer(long long a, long long b, long long c){
    if(b == 0) return 1;
    if(b == 1) return a % c;
    long long value = answer (a, b / 2 , c);
    if(b % 2 == 0) return value * value % c;
    else return (value * value % c) * a % c;
}

int main(){
    long long a; long long b; long long c;
    cin >> a >> b >> c;
    cout << answer(a, b, c);
}
