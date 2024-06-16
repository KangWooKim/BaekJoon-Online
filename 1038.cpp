// https://www.acmicpc.net/problem/1038

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generate_decreasing_numbers(vector<long long> &numbers, long long current, int last_digit) {
    if (current > 9876543210LL) return;  // 최대 감소하는 수는 9876543210
    numbers.push_back(current);
    for (int next_digit = last_digit - 1; next_digit >= 0; --next_digit) {
        generate_decreasing_numbers(numbers, current * 10 + next_digit, next_digit);
    }
}

int main() {
    int N;
    cin >> N;

    if (N < 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<long long> decreasing_numbers;

    for (int start_digit = 0; start_digit <= 9; ++start_digit) {
        generate_decreasing_numbers(decreasing_numbers, start_digit, start_digit);
    }

    sort(decreasing_numbers.begin(), decreasing_numbers.end());

    if (N >= decreasing_numbers.size()) {
        cout << -1 << endl;
    } else {
        cout << decreasing_numbers[N] << endl;
    }

    return 0;
}
