// https://www.acmicpc.net/problem/1978

#include <bits/stdc++.h>
using namespace std;

bool prime[1001];

void era(){
    for(int i = 2 ; i < 1001 ; i++){
        if(prime[i] == true){
            for(int k = i * 2 ; k < 1001 ; k = k + i)
                prime[k] = false;
        }
    }
}

int main(){
    for(int i = 0 ; i < 1001 ; i++) prime[i] = true;
    prime[1] = false;
    era();
    int answer = 0;
    int res;
    cin >> res;
    while(res > 0){
        int k;
        cin >> k;
        if(prime[k]) answer++;
        res--;
    }
    cout << answer;
    return 0;
}
