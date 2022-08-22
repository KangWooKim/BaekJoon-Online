// https://www.acmicpc.net/problem/4948

#include <bits/stdc++.h>
using namespace std;
bool prime[246913];

void era(){
    for(int i = 2 ; i < 246913 ; i++){
        if(prime[i] == true){
            for(int k = i * 2 ; k < 246913 ; k = k + i)
                prime[k] = false;
        }
    }
}
int main(){
    for(int i = 0 ; i < 246913 ; i++) prime[i] = true;
    prime[1] = false;
    era();
    int res = 0;
    int val;
    cin >> val;
    if(val == 0) return 0;
    do{
        for(int i = val + 1 ; i <= 2 * val ; i++){
            if(prime[i]) res++;
        }
        cout << res << '\n';
        cin >> val;
        res = 0;
    }while(val != 0);
    return 0;
}
