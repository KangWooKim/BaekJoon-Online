// https://www.acmicpc.net/problem/1427

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string N;
    cin >> N;
    stable_sort(N.rbegin(), N.rend());
    cout << N;
    return 0;

}
