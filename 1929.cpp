// https://www.acmicpc.net/problem/1929

#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];

void era(){
    for(int i = 2 ; i < 1000001 ; i++){
        if(prime[i] == true){
            for(int k = i * 2 ; k < 1000001 ; k = k + i)
                prime[k] = false;
        }
    }
}
int main(){
    int x, y;
    cin >> x >> y;
    for(int i = 0 ; i < 1000001 ; i++) prime[i] = true;
    prime[1] = false;
    era();
    for(int i = x ; i <= y ; i++){
        if(prime[i] == true) cout << i << '\n';
    }
    return 0;
}
