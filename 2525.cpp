//https://www.acmicpc.net/problem/2525

#include <bits/stdc++.h>
using namespace std;
int main(){
    int hour, minute, time;
    cin >> hour >> minute;
    cin >> time;
    minute += time;
    if(minute > 59){
        hour = hour + (minute / 60);
        minute %= 60;
        
        if(hour > 23) hour %= 24;
    }
    cout << hour << " " << minute;
    return 0;
}
