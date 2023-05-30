// https://www.acmicpc.net/problem/1027

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> building, answer;

double calculate(int i, int j){
    return ((double)building[j] - (double)building[i]) / ((double)j - (double)i);
}

int main(){
    cin >> n;
    if(n <= 1) {cout << 0; return 0;}
    building = vector<int>(n);
    answer = vector<int>(n, 0);
    for(int i = 0 ; i < n ; i++)
        cin >> building[i];
    
    for(int i = 0 ; i < n - 1 ; i++){
        double max_slope = calculate(i, i + 1);
        ++answer[i]; ++answer[i + 1];
        for(int j = i + 2 ; j < n ; j++){
            double slope = calculate(i, j);
            if(max_slope < slope){
                max_slope = slope;
                ++answer[i]; ++answer[j];
            }
            else{
                continue;
            }
        }
    }
    int a = *max_element(answer.begin(), answer.end());
    cout << a;
    return 0;
}
