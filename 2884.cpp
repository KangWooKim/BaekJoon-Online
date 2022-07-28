// https://www.acmicpc.net/problem/2884

#include <bits/stdc++.h>
using namespace std;
int main(){
    int hour, minute;
    cin >> hour >> minute;
    minute -= 45;
    if(minute < 0){
        minute += 60;
        hour--;
        if(hour < 0) hour = 23;
    }
    cout << hour << " " << minute;
    return 0;
}
