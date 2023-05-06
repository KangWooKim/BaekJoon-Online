// https://www.acmicpc.net/problem/10845

#include <bits/stdc++.h>
using namespace std;
queue<int> q;
void custom_pop(){
    if(q.empty()){cout << -1 << "\n"; return;}
    cout << q.front() << "\n";
    q.pop();
    return;
}

void custom_size(){
    cout << q.size() << "\n";
    return;
}

void custom_empty(){
    if(q.size() == 0) cout << 1 << "\n";
    else cout << 0 << "\n";
    return;
}

void custom_front(){
    if(q.size() == 0) cout << -1 << "\n";
    else cout << q.front() << "\n";
    return;
}

void custom_back(){
    if(q.size() == 0) cout << -1 << "\n";
    else cout << q.back() << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;
    while(TC--){
        string order; int i;
        cin >> order;
        if(order == "push"){cin >> i; q.push(i);}
        else if(order == "pop"){custom_pop();}
        else if(order == "size"){custom_size();}
        else if(order == "empty"){custom_empty();}
        else if(order == "front"){custom_front();}
        else if(order == "back"){custom_back();}
    }
    return 0;
}
