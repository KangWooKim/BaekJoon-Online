// https://www.acmicpc.net/problem/6571

#include <iostream>
#include <vector>
#include <algorithm>

bool isLessOrEqual(const std::string &a, const std::string &b) {
    if (a.size() < b.size()) return true;
    if (a.size() > b.size()) return false;
    return a <= b;
}

std::string add(const std::string &a, const std::string &b) {
    std::string res;
    int carry = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry; --i, --j) {
        int x = (i >= 0) ? a[i] - '0' : 0;
        int y = (j >= 0) ? b[j] - '0' : 0;
        res.push_back((x + y + carry) % 10 + '0');
        carry = (x + y + carry) / 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::vector<std::string> fib = {"1", "2"};
    while (fib.back().size() <= 100) {
        fib.push_back(add(fib[fib.size() - 1], fib[fib.size() - 2]));
    }

    std::string a, b;
    while (std::cin >> a >> b && (a != "0" || b != "0")) {
        int cnt = 0;
        for (const std::string &f : fib) {
            if (isLessOrEqual(a, f) && isLessOrEqual(f, b)) {
                ++cnt;
            }
        }
        std::cout << cnt << std::endl;
    }

    return 0;
}
