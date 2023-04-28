// https://www.acmicpc.net/problem/1141

#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return a.length() < b.length();
}

int main(){
    int cnt;
    cin >> cnt;
    vector<string> list;
    while(cnt--){
        string s;
        cin >> s;
        list.push_back(s);
    }
    stable_sort(list.begin(), list.end(), cmp);
    set<string> st; int answer = 0;
    for(int i = list.size() - 1 ; i >= 0 ; i--){
        if(st.count(list[i]) == 1) continue;
        else{
            ++answer;
            for(int k = 1 ; k <= list[i].length() ; k++){
                string s = list[i].substr(0, k);
                st.insert(s);
            }
        }
    }
    cout << answer << endl;
    return 0;
}
