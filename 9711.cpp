// https://www.acmicpc.net/problem/9711

#include <bits/stdc++.h>
#define FastFC cin.tie(NULL),cout.tie(NULL),ios::sync_with_stdio(false)
using namespace std;

int main(){
    FastFC;
    long long cnt;
    cin >> cnt;
    for(int i = 1 ; i <= cnt ; i++){
        long long P, Q;
        cin >> P >> Q;
        long long first = 1;
        long long second = 1;
        long long ans;
        if(P == 1 || P == 2) ans = 1;
        else{
            for(long long j = 3 ; j <= P ; j++){
                ans = (first + second) % Q;
                second = first % Q;
                first = ans % Q;
            }
        }
        cout << "Case #" << i << ": " << ans % Q << "\n";
    }
    return 0;
}
