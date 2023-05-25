// https://www.acmicpc.net/problem/24385

#include <bits/stdc++.h>
using namespace std;
string s;


int main(){
    cin >> s;
    sort(s.begin(), s.end());
    do{
        cout << s << "\n";
    }while(next_permutation(s.begin(), s.end()));
    return 0;
}
