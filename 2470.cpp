// https://www.acmicpc.net/problem/2470

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> solutions(N);

    for (int i = 0; i < N; ++i) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    int left = 0, right = N - 1;
    int closestSum = numeric_limits<int>::max();
    int solution1 = 0, solution2 = 0;

    while (left < right) {
        int sum = solutions[left] + solutions[right];

        if (abs(sum) < abs(closestSum)) {
            closestSum = sum;
            solution1 = solutions[left];
            solution2 = solutions[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    cout << solution1 << " " << solution2 << endl;

    return 0;
}
