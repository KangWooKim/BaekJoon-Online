// https://www.acmicpc.net/problem/10819

#include <bits/stdc++.h> 
using namespace std; 
int n; vector<int> a; int max_value = -1000;

void swapping(int x, int y){
    int tmp = a[x]; a[x] = a[y]; a[y] = tmp; 
}

void calc(){ 
    int tmp = 0; 
    for(int i = 1 ; i < a.size() ; i++){
        tmp += abs(a[i - 1] - a[i]); 
    } 
    max_value = max(tmp, max_value); 
}

void dfs(int idx){
    for(int i = idx + 1 ; i < a.size() ; i++){
        for(int j = i + 1 ; j < a.size() ; j++){
            swapping(i, j); 
            calc(); 
            dfs(i); 
            swapping(i, j); 
        } 
    } 
    return; 
}

int main(){ 
    cin >> n; 
    a = vector<int>(n); 
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    } 
    calc();
    dfs(-1); 
    cout << max_value;
    return 0; 
}

/*
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int max_value = -1000;

void calc(){
    int tmp = 0;
    for(int i = 1 ; i < a.size() ; i++){
        tmp += abs(a[i - 1] - a[i]);
    }
    max_value = max(tmp, max_value);
}

int main(){
    cin >> n;
    a = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());// 배열을 정렬하여 next_permutation을 적용할 수 있는 상태로 만듭니다.
    do {
        calc();
    } while (next_permutation(a.begin(), a.end())); // 모든 순열을 계산한다.

    cout << max_value << "\n";
    return 0;
}

*/
