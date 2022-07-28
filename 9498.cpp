// https://www.acmicpc.net/problem/9498

#include <bits/stdc++.h>
using namespace std;
int main(){
    int score;
    cin >> score;
    if(score > 89) cout << "A";
    else if(score > 79) cout << "B";
    else if(score > 69) cout << "C";
    else if(score > 59) cout << "D";
    else cout << "F";
    return 0;
}
