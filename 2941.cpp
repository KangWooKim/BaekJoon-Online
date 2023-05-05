// https://www.acmicpc.net/problem/2941

#include <bits/stdc++.h>
using namespace std;

int main(){
    string alpha;
    cin >> alpha;
    unordered_set<string> st;
    st.insert("c=");
    st.insert("c-");
    st.insert("dz=");
    st.insert("d-");
    st.insert("lj");
    st.insert("nj");
    st.insert("s=");
    st.insert("z=");
    int answer = 0;
    if(alpha.length() == 1) cout << 1;
    else{
        for(int i = 0 ; i < alpha.length() - 1 ; i++){
            if(st.count(alpha.substr(i, 2)) != 0) {answer++; i++;}
            if(i < alpha.length() - 2 && st.count(alpha.substr(i, 3)) != 0) {answer += 2; i += 2;}
        }
        cout << alpha.length() - answer;
    }
    
    return 0;
}
