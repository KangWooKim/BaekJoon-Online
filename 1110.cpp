// https://www.acmicpc.net/problem/1110

#include <iostream>

using namespace std;

int main() {
    int n, original, cycle_length = 0;
    cin >> n;
    original = n;

    do {
        int right_digit = n % 10;
        int left_digit = n / 10;
        int sum = left_digit + right_digit;
        n = (right_digit * 10) + (sum % 10);
        cycle_length++;
    } while (original != n);

    cout << cycle_length << endl;

    return 0;
}
