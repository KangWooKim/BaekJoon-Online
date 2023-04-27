// https://www.acmicpc.net/problem/1181

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cnt;
    cin >> cnt;
    int max_length = 0;
    map<int, vector<string>> words;
    while(cnt--){
        string word;
        cin >> word;
        words[word.length()].push_back(word);
        max_length = max_length < word.length() ? word.length() : max_length;
    }
    for(int length = 1 ; length <= max_length ; length++){
        vector<string> v = words[length];
        if(v.empty()) continue;
        stable_sort(v.begin(), v.end());
        cout << v[0] << endl;
        for(int i = 1 ; i < v.size() ; i++){
            if(v[i] != v[i - 1])
                cout << v[i] << endl;
        }
    }
    
    return 0;
}
