// https://www.acmicpc.net/problem/1351

#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

ll N, P, Q;
map<ll, ll> cache;

ll ans(ll n, ll p, ll q) {
    if (n == 0) return 1;
    if (cache.count(n) > 0) return cache[n];
    
    cache[n] = ans(n / p, p, q) + ans(n / q, p, q);
    return cache[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> P >> Q;

    cout << ans(N, P, Q) << endl;

    return 0;
}
