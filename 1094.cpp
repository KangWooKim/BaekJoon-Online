#include <iostream>
using namespace std;

int countSticks(int X) {
    int count = 0;
    while (X > 0) {
        if (X % 2 == 1) {
            count++;
        }
        X /= 2;
    }
    return count;
}

int main() {
    int X;
    cin >> X;
    cout << countSticks(X) << endl;
    return 0;
}
