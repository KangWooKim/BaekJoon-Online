// https://www.acmicpc.net/problem/10773

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K;
    cin >> K;
    vector<long long> v; long long sum = 0;
    while(K--){
        long long i;
        cin >> i;
        if(i == 0) {sum -= v.back(); v.pop_back();}
        else{
            v.push_back(i);
            sum += i;
        }
    }
    cout << sum;
    return 0;
}
