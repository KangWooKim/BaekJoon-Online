// https://www.acmicpc.net/problem/24417

#include <bits/stdc++.h>
using namespace std;
#define val 1000000007;

int main(){
    unsigned long long n;
    cin >> n;
    int first = 1; int second = 1;
    for(unsigned long long i = 3 ; i <= n ; i++){
        int ans = (first + second) % val;
        second = first;
        first = ans;
    }
    cout << first << ' ' << (n - 2);
    return 0;
}
