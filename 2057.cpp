#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_factorial_sum(ll n) {
    vector<ll> factorials;
    ll fact = 1;
    for (ll i = 1; fact <= n; ++i) {
        factorials.push_back(fact);
        fact *= i;
    }

    int size = factorials.size();
    for (int i = size - 1; i >= 0; --i) {
        if (n >= factorials[i]) {
            n -= factorials[i];
        }
        if (n == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    ll n;
    cin >> n;

    if (is_factorial_sum(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
