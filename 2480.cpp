// https://www.acmicpc.net/problem/2480

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, prize;
    cin >> a >> b >> c;
    if((a == b) && (b == c)) prize = 10000 + 1000 * a;
    else if(a == b) prize = 1000 + 100 * a;
    else if(a == c) prize = 1000 + 100 * a;
    else if(b == c) prize = 1000 + 100 * b;
    else prize = 100 * max(a, max(b, c));
    cout << prize;
    return 0;
}
