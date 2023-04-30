// https://www.acmicpc.net/problem/1193

#include <bits/stdc++.h>
using namespace std;

void printing(int a, int b){
    if(a % 2 == 0){
        cout << b << '/' << a + 1 - b;
        return;
    }
    else{
        cout << a + 1 - b << '/' << b;
        return;
    }
}

int main(){
    int X;
    cin >> X;
    int res;
    for(int i = 1 ; i < 10000000 ; i++){
        if(X - i > 0){
            X -= i; continue;
        }
        else if(X - i == 0){
            res = i; X = i;
            break;
        }
        else if(X - i < 0){
            res = i;
            break;
        }
    }
    printing(res, X);
    return 0;
}
