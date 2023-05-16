// https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int min_chicken_distance = INT_MAX;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<pair<int, int>> selected_chickens;

int calc_chicken_distance() {
	int total_distance = 0;
	for (auto &house : houses) {
		int dist = INT_MAX;
		for (auto &chicken : selected_chickens) {
			dist = min(dist, abs(house.first - chicken.first) + abs(house.second - chicken.second));
		}
		total_distance += dist;
	}
	return total_distance;
}

void select_chickens(int idx, int cnt) {
	if (cnt == M) {
		min_chicken_distance = min(min_chicken_distance, calc_chicken_distance());
		return;
	}
	if (idx == chickens.size()) {
		return;
	}
	selected_chickens.push_back(chickens[idx]);
	select_chickens(idx + 1, cnt + 1);
	selected_chickens.pop_back();
	select_chickens(idx + 1, cnt);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				houses.push_back({i, j});
			} else if (tmp == 2) {
				chickens.push_back({i, j});
			}
		}
	}
	select_chickens(0, 0);
	cout << min_chicken_distance << endl;
	return 0;
}
