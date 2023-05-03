// https://www.acmicpc.net/problem/5430

#include <bits/stdc++.h>
using namespace std;

void printing(const vector<int>& v) {
    cout << '[';
    if (!v.empty()) {
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << ',';
        }
        cout << v.back();
    }
    cout << ']' << "\n";
}


int main(){
    int TestCase;
    cin >> TestCase;
    while(TestCase--){
        string order;
        cin >> order;
        int len;
        cin >> len;
        vector<int> v;
        string inputArr;
        cin >> inputArr;
        int i = 1;
        int num = 0;
        while (i < inputArr.length()) {
            if (isdigit(inputArr[i])) {
                num = num * 10 + (inputArr[i] - '0');
            }
            else {
                if (num) {
                    v.push_back(num);
                    num = 0;
                }
            }
            i++;
        }
        int R = 0; int F = 0; int B = 0;
        for(auto& c : order){
            if(c == 'R') R++;
            else if(c == 'D' && R % 2 == 0) F++;
            else if(c == 'D' && R % 2 == 1) B++;
        }
        vector<int> p;
        if(F + B > v.size()) {cout << "error" << "\n"; continue;}
        else{
            if(R % 2 == 0){
                for(int i = F ; i < v.size() - B ; i++){
                    p.push_back(v[i]);
                }
            }
            else{
                for(int i = v.size() - 1 - B ; i >= F ; i--){
                    p.push_back(v[i]);
                }
            }
        }
        printing(p);
    }
    return 0;
}
