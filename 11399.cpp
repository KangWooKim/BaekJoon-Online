// https://www.acmicpc.net/problem/11399

#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> timeList;
    int people;
    cin >> people;
    for(int i = 0 ; i < people ; i++){
        int t; cin >> t;
        timeList.push_back(t);
    }
    sort(timeList.begin(), timeList.end());
    for(int i = 1 ; i < timeList.size() ; i++){
        timeList[i] = timeList[i] + timeList[i - 1];
    }
    int sum = accumulate(timeList.begin(), timeList.end(), 0);
    cout << sum;
    return 0;
}
