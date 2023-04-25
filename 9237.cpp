// https://www.acmicpc.net/problem/9237

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> growth_days(n);
    for(int i = 0; i < n; i++){
        cin >> growth_days[i];
    }

    sort(growth_days.rbegin(), growth_days.rend());

    int max_invite_day = growth_days[0] + 1;
    for(int i = 1; i < n; i++){
        max_invite_day = max(max_invite_day, i + growth_days[i] + 1);
    }

    cout << max_invite_day + 1;
    return 0;
}
