// https://www.acmicpc.net/problem/4344

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        double avg = 0;
        cin >> n;

        vector<int> scores(n);
        for (int i = 0; i < n; i++) {
            cin >> scores[i];
            avg += scores[i];
        }

        avg /= n;
        int above_avg_count = 0;

        for (int score : scores) {
            if (score > avg) {
                above_avg_count++;
            }
        }

        double percentage = 100.0 * above_avg_count / n;
        cout << fixed << setprecision(3) << percentage << "%" << endl;
    }

    return 0;
}
