#include <bits/stdc++.h>

using namespace std;

#define MAX 20

int T, N, M, prevented, ans;
int city[MAX][MAX];
bool visit[MAX][MAX];

int getHouseCnt(int r, int c, int k) {
	int house = 0;

	// i는 행의 시작부터 끝, j는 열의 시작부터 끝
	for (int i = r - k + 1; i <= r + k - 1; i++) {
		for (int j = c - k + 1; j <= c + k - 1; j++) {
			// 좌표 벗어남
			if (i < 0 || i >= N || j < 0 || j >= N)
				continue;

			// 중심으로부터 거리
			int d = abs(r - i) + abs(c - j);
			if (d <= k - 1 && city[i][j] == 1)
				house++;
		}
	}
	return house;
}

void solution() {
	for (int k = 1; k <= N + 1; k++) {
		int cost = k * k + (k - 1) * (k - 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int houseCnt = getHouseCnt(i, j, k);

				// 이익
				int margin = houseCnt * M - cost;

				if (margin >= 0) {
					ans = (houseCnt > ans) ? houseCnt : ans;
				}
			}
		}
	}

}

int main() {

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (int i = 1; i <= T; i++) {
		memset(city, 0, sizeof city);
		ans = 0;

		cin >> N >> M;

		for (int m = 0; m < N; m++) {
			for (int n = 0; n < N; n++) {
				cin >> city[m][n];
			}
		}

		solution();

		cout << "#" << i << " " << ans << endl;
	}

	return 0;
}
