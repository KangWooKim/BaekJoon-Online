// https://www.acmicpc.net/problem/14681

#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y;
    cin >> x;
    cin >> y;
    if(x > 0 && y > 0) cout << 1;
    else if(x < 0 && y > 0) cout << 2;
    else if(x < 0 && y < 0) cout << 3;
    else if(x > 0 && y < 0) cout << 4;
    return 0;
}
