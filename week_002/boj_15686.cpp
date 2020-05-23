#include <bits/stdc++.h>

using namespace std;

#define MAX 51
const int INF = 987654321;

int N, M;
int arr[MAX][MAX];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int ans;

void solution() {

	// 선택에 쓸 치킨집 vector
	vector<int> selected;
	for (int i = 0; i < chicken.size(); i++) {
		if (i >= chicken.size() - M)
			selected.push_back(1);
		else
			selected.push_back(0);
	}

	do {
		// 각 집마다 거리 계산할 vec
		vector<int> dist(house.size(), 100);

		for (int i = 0; i < house.size(); i++) {
			int dis = INF;
			int x = house[i].first;
			int y = house[i].second;

			for (int j = 0; j < chicken.size(); j++) {
				// 선택된 치킨집x
				if (selected[j] == 0)
					continue;

				int m = chicken[j].first;
				int n = chicken[j].second;

				// 치킨집까지의 거리
				int dis = abs(x - m) + abs(y - n);

				// 기존 거리보다 짧을 때 변경
				if (dist[i] > dis)
					dist[i] = dis;
			}
		}

		int sum = 0;
		for (vector<int>::iterator it = dist.begin(); it != dist.end(); it++) {
			sum += *it;
		}
		ans = (ans > sum) ? sum : ans;
	} while (next_permutation(selected.begin(), selected.end()));
}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) { // 치킨집이면 push
				chicken.push_back(make_pair(i, j));
			} else if (arr[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
		}
	}

	ans = INF;

	solution();

	cout << ans;
	return 0;
}
