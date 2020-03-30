#include <bits/stdc++.h>

using namespace std;

#define MAX 8
int N, M; // N*M
int cnt; // 벽 개수
int ans; // 안전구역 개수
int arr[MAX][MAX];
int tmp[MAX][MAX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void copyArr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
}

void spreadVirus() {
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 2) { // 바이러스면
				q.push(make_pair(i, j));
			}
		}
	}

	// dfs
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		tmp[x][y] = 2; // 바이러스 퍼짐
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) { // 범위 내이고
				if (tmp[nx][ny] == 0) { // 바이러스 퍼질 수 있으면
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void countArea() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0)
				cnt++;
		}
	}
	ans = (ans < cnt) ? cnt : ans;
}

void wall(int cnt) {
	if (cnt == 3) { // 벽 세 개 세웠을 경우
		// 복사
		copyArr();
		// 바이러스 퍼트림
		spreadVirus();
		// 개수 세기
		countArea();
		return;
	}

	// 벽 세우기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(cnt + 1);
				arr[i][j] = 0; // 빈공간으로 변경
			}
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	// 1 : 벽, 2 : 바이러스, 0 : 빈공간
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				// 벽 세울 수 있는 위치라면 벽 세움
				arr[i][j] = 1;
				wall(1);
				arr[i][j] = 0;
			}
//printMap();
		}
	}

	cout << ans;

	return 0;
}
