// https://www.acmicpc.net/problem/1354

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, P, Q, X, Y;
map<ll, ll> cache;
ll ans(ll N, ll P, ll Q, ll X, ll Y){
    if(N <= 0) return 1;
    if(cache.count(N) > 0) return cache[N];
    return cache[N] = ans((N / P) - X, P, Q, X, Y) + ans((N / Q) - Y, P, Q, X, Y);
}

int main(){
    cin >> N >> P >> Q >> X >> Y;
    cout << ans(N, P, Q, X, Y) << endl;
    return 0;
}
