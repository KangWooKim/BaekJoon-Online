// https://www.acmicpc.net/problem/1062

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K;
vector<int> words;
int answer = 0;

void countReadable(int mask, int k, int idx) {
    if (k == K) { // K개의 글자를 모두 가르쳤으면, 읽을 수 있는 단어 수를 세어본다.
        int count = 0;
        for (int word : words) {
            if ((word & mask) == word) // 단어에 필요한 모든 글자를 가르쳤는지 확인한다.
                count++;
        }
        answer = max(answer, count);
        return;
    }
    
    for (int i = idx; i < 26; ++i) { // 'a'부터 'z'까지 반복
        if ((mask & (1 << i)) == 0) { // 현재 글자를 가르치지 않았다면 가르치고 다음으로 넘어간다.
            countReadable(mask | (1 << i), k + 1, i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    words.resize(N);

    // 기본적으로 'a', 'n', 't', 'i', 'c'는 항상 배워야 하는 글자이므로 mask에 설정한다.
    int essential = (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));
    if (K < 5) { // 만약 K가 5 미만이면 어떤 단어도 읽을 수 없다.
        cout << 0 << "\n";
        return 0;
    }

    K -= 5; // 이미 5개의 필수 글자를 가르쳤기 때문에 K에서 빼준다.

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        int word_mask = 0;
        for (char ch : word) {
            word_mask |= (1 << (ch - 'a')); // 각 단어를 비트마스크로 변환한다.
        }
        words[i] = word_mask;
    }

    countReadable(essential, 0, 0);
    cout << answer << "\n";
    
    return 0;
}
