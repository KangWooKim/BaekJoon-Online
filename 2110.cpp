// https://www.acmicpc.net/problem/2110

#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int arr[200000];

// 간격이 distance일 때 설치 가능한 공유기의 개수 반환
int possible(int distance) {
    int cnt = 1;
    int last_pos = arr[0];  // 첫 번째 집에는 강제로 공유기를 설치하고 시작합니다.
    for (int i = 1; i < n; i++) {
        if ((arr[i] - last_pos) >= distance) {
            cnt++;
            last_pos = arr[i];
        }
    }
    return cnt;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);  // 이진 탐색을 위해 집의 좌표를 정렬합니다.
    int left = 1, right = arr[n - 1] - arr[0];
    int answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (possible(mid) >= c) {  // c개의 공유기를 설치할 수 있는 경우
            answer = mid;  // 정답 후보 갱신
            left = mid + 1;
        } else {  // c개의 공유기를 설치할 수 없는 경우
            right = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}
