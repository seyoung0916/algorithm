#include <bits/stdc++.h>

using namespace std;

#define MAX 21

int N, ans = 987654321;
int arr[MAX][MAX];
int gu[MAX][MAX];

void cal() {
	vector<int> population(6, 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			population[gu[i][j]] += arr[i][j];
		}
	}
	ans = min(ans,
			*max_element(population.begin() + 1, population.end())
					- *min_element(population.begin() + 1, population.end()));
}

void checking(int x, int y, int d1, int d2) {

	int idx; // 경계선 구분 용도
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			gu[i][j] = 5;
		}
	}

// 1구역
	idx = 0;
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (i == x + idx && j == y - idx) { // 5구역 경계
				idx++;
				break;
			}
			gu[i][j] = 1;
		}
	}

// 2구역
	idx = 1;
	for (int i = 1; i <= x + d2; i++) {
		for (int j = N; j >= y + 1; j--) {
			if (i == x + idx && j == y + idx) {
				idx++;
				break;
			}
			gu[i][j] = 2;
		}
	}

// 3구역
	idx = 0;
	for (int i = x + d1; i <= N; i++) {
		for (int j = 1; j < y + d2 - d1; j++) {
			if (i == x + d1 + idx && j == y - d1 + idx) {
				idx++;
				break;
			}
			gu[i][j] = 3;
		}
	}

// 4구역
	idx = 1;
	for (int i = x + d2 + 1; i <= N; i++) {
		for (int j = N; j >= y + d2 - d1; j--) {
			if (i == x + d2 + idx && j == y + d2 - idx) {
				idx++;
				break;
			}
			gu[i][j] = 4;
		}
	}
	cal();
}

void dSelect() {

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (x + d1 + d2 <= N && y - d1 >= 1 && y - d1 <= N
							&& y + d2 <= N) {
						checking(x, y, d1, d2);
					}
				}
			}
		}
	}
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	dSelect();
	cout << ans << endl;

	return 0;
}
