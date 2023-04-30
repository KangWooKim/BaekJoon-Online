// https://www.acmicpc.net/problem/4673

#include <bits/stdc++.h>
using namespace std;

int self(int k){
    int a = k;
    for(int i = 1000 ; i > 1 ; i /= 10){
        a += k / i;
        k %= i;
    }
    a += k;
    return a;
}

int main(){
    vector<bool> v(10001, true);
    for(int i = 1 ; i < v.size() ; i++){
        
            int k = self(i);
            for(; k < v.size() ; k = self(k)){
                v[k] = false;
            }
        
    }
    for(int i = 1 ; i < v.size() ; i++){
        if(v[i]){
            cout << i << endl;
        }
    }
    return 0;
}
