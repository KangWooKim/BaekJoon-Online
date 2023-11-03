// https://www.acmicpc.net/problem/1107

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 고장난 버튼인지 체크하는 함수
bool isBroken(int channel, const vector<bool>& brokenButtons) {
    if (channel == 0) return brokenButtons[0];
    while (channel > 0) {
        if (brokenButtons[channel % 10]) return true;
        channel /= 10;
    }
    return false;
}

// 채널까지 누를 버튼의 수를 반환하는 함수
int countPresses(int channel) {
    if (channel == 0) return 1;
    int length = 0;
    while (channel > 0) {
        length++;
        channel /= 10;
    }
    return length;
}

int main() {
    int N, M, button;
    cin >> N >> M;
    vector<bool> brokenButtons(10, false);
    for (int i = 0; i < M; ++i) {
        cin >> button;
        brokenButtons[button] = true;
    }

    // +와 - 버튼만으로 이동하는 경우
    int minPresses = abs(N - 100);
    
    // 0부터 1000000까지 모든 채널을 검사 (500000까지이지만 채널이 무한대로 주어지므로 여유를 둠)
    for (int channel = 0; channel <= 1000000; ++channel) {
        if (!isBroken(channel, brokenButtons)) {
            int presses = countPresses(channel) + abs(channel - N);
            minPresses = min(minPresses, presses);
        }
    }

    cout << minPresses;
    return 0;
}
