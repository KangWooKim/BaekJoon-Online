// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    sort(meetings.begin(), meetings.end(), compare);

    int max_meetings = 0;
    int current_end_time = 0;

    for (int i = 0; i < N; ++i) {
        if (current_end_time <= meetings[i].first) {
            current_end_time = meetings[i].second;
            max_meetings++;
        }
    }

    cout << max_meetings << endl;

    return 0;
}
