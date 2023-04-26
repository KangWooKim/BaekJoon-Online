// https://www.acmicpc.net/problem/2156

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt;
    cin >> cnt;
    vector<int> wine;
    while(cnt--){
        int w;
        cin >> w;
        wine.push_back(w);
    }
    if(wine.size() == 1){
        cout << wine[0] << endl;
        return 0;
    }
    else if(wine.size() == 2){
        cout << wine[0] + wine[1] << endl;
        return 0;
    }
    vector<pair<int, int>> v(wine.size() , make_pair(0, 0));
    v[0].first = 0; v[0].second = wine[0];
    v[1].first = wine[0]; v[1].second = wine[0] + wine[1];
    v[2].first = wine[0] + wine[1]; v[2].second = wine[2] + max(wine[0], wine[1]);
    for(int i = 3 ; i < v.size() ; i++){
        v[i].first = max(v[i - 1].second, v[i - 1].first);
        v[i].second = max(v[i - 2].first + wine[i - 1] + wine[i], v[i - 2].second + wine[i]);
    }
    cout << max(v[v.size() - 1].first, v[v.size() - 1].second) << endl;
    return 0;
}
