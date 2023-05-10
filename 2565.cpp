// https://www.acmicpc.net/problem/2565

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> line(n);
    for(int i = 0; i < n; i++)
        cin >> line[i].first >> line[i].second;
    
    // A 전봇대의 전깃줄 위치에 따라 정렬
    sort(line.begin(), line.end());

    // LIS를 찾기 위한 DP 테이블 생성
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(line[j].second < line[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    // 전체 전깃줄의 개수에서 LIS의 길이를 뺀 값 출력
    cout << n - *max_element(dp.begin(), dp.end());
    return 0;
}
