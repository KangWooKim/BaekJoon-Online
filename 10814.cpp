// https://www.acmicpc.net/problem/10814

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // 나이의 범위는 1 ~ 200
    vector<vector<string>> ageList(201);  // 각 나이에 대응하는 이름 목록을 저장
    
    for (int i = 0; i < N; ++i) {
        int age;
        string name;
        cin >> age >> name;
        ageList[age].push_back(name);  // 해당 나이에 이름 추가
    }
    
    // 출력
    for (int age = 1; age <= 200; ++age) {
        for (const string& name : ageList[age]) {
            cout << age << " " << name << endl;
        }
    }

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, string>> jl;
    for (int i = 0; i < N; ++i) {
        int age;
        string name;
        cin >> age >> name;
        jl.push_back(make_pair(age, name));
    }
    
    // stable_sort로 나이 기준만 정렬
    stable_sort(jl.begin(), jl.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        return a.first < b.first; // 나이만 비교
    });
    
    // 출력 형식 수정 (공백 추가)
    for (int i = 0; i < N; ++i) {
        cout << jl[i].first << " " << jl[i].second << endl;
    }

    return 0;
}
