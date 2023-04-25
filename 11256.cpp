// https://www.acmicpc.net/problem/11256

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int TestCase;
    cin >> TestCase;
    while(TestCase--){
        int J, N;
        cin >> J >> N;
        vector<int> box_sizes(N);
        for(int i = 0; i < N; i++){
            int r, c;
            cin >> r >> c;
            box_sizes[i] = r * c;
        }
        sort(box_sizes.rbegin(), box_sizes.rend());
        
        int answer = 0;
        for(const auto& size : box_sizes){
            J -= size;
            answer++;
            if(J <= 0) break;
        }
        
        cout << answer << endl;
    }
    return 0;
}
