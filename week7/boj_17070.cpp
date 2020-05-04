#include <bits/stdc++.h>

using namespace std;

#define MAX 16

int N, ans;
int arr[MAX][MAX], tmp[MAX][MAX];
// 가로, 세로, 대각선
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

void dfs(int x, int y, int op) {

	if (x == N - 1 && y == N - 1) {
		ans++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (op == 0 && i == 1)
			continue;
		if (op == 1 && i == 0)
			continue;
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 범위
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		// 목적지가 벽 x 이거나 파이프가 차지하는 자리 x
		if (arr[nx][ny] != 0)
			continue;
		// 대각선은 두 칸이 빈 곳이어야 함
		if (i == 2) {
			if (arr[nx - 1][ny] != 0 || arr[nx][ny - 1] != 0)
				continue;
		}

		dfs(nx, ny, i);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// 첫 두 칸 차지
	arr[0][0] = -1;
	arr[0][1] = -1;
	dfs(0, 1, 0);

	cout << ans << endl;
	return 0;
}
