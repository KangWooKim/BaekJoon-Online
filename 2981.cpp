// https://www.acmicpc.net/problem/2981

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최대공약수를 구하는 함수
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    vector<int> numbers(N);

    // 주어진 수들을 입력 받음
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    // 주어진 수들을 정렬
    sort(numbers.begin(), numbers.end());

    // 첫 번째 수와 두 번째 수의 차이를 최대공약수의 초기값으로 설정
    int g = numbers[1] - numbers[0];
    for (int i = 2; i < N; ++i) {
        // 나머지 수들과의 차이의 최대공약수를 구함
        g = gcd(g, numbers[i] - numbers[i - 1]);
    }

    // 최대공약수의 약수들을 찾아 벡터에 저장
    vector<int> divisors;
    for (int i = 2; i <= g / i; ++i) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i != g / i) divisors.push_back(g / i);
        }
    }

    // 1은 M이 될 수 없으므로 추가하지 않음
    divisors.push_back(g);

    // 약수들을 정렬
    sort(divisors.begin(), divisors.end());

    // 약수들을 출력
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
