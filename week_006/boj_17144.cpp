#include <bits/stdc++.h>

using namespace std;

#define MAX 50

int R, C, T;
int room[MAX][MAX];
queue<pair<pair<int, int>, int>> dust;
int start, finish, ans;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void spread() {
	while (!dust.empty()) {
		int x = dust.front().first.first;
		int y = dust.front().first.second;
		int cur = dust.front().second;
		dust.pop();
		if (cur == 0) continue;

		//cout << "x " << x << " y " << y << " cur " << cur << endl;
		int cnt = 0; // 확산된 방향 수
		int mnt = cur / 5; // 확산될 양

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (room[nx][ny] == -1) // 공기청정기로는 확산 x
				continue;

			cnt++;
			room[nx][ny] += mnt;
		}
		room[x][y] -= (mnt * cnt);
	}
}

void clean() {
	// 위
	for (int i = start - 2; i >= 0; i--)
		room[i + 1][0] = room[i][0];

	for (int i = 1; i <= C - 1; i++)
		room[0][i - 1] = room[0][i];

	for (int i = 1; i <= start; i++)
		room[i - 1][C - 1] = room[i][C - 1];

	for (int i = C - 2; i >= 1; i--)
		room[start][i + 1] = room[start][i];

	room[start][1] = 0;

	// 아래
	for (int i = finish + 2; i <= R - 1; i++)
		room[i - 1][0] = room[i][0];

	for (int i = 1; i <= C - 1; i++)
		room[R - 1][i - 1] = room[R - 1][i];

	for (int i = R - 2; i >= finish; i--)
		room[i + 1][C - 1] = room[i][C - 1];

	for (int i = C - 2; i >= 1; i--)
		room[finish][i + 1] = room[finish][i];

	room[finish][1] = 0;
}

int main() {

	cin >> R >> C >> T;
	int idx = 1;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			// 공기 청정기
			if (room[i][j] == -1) {
				if (idx == 1) {
					start = i;
					idx++;
				} else {
					finish = i;
				}
			}
		}
	}

	for (int i = 0; i < T; i++) {
		// 먼지 위치
		for (int m = 0; m < R; m++) {
			for (int n = 0; n < C; n++) {
				if (room[m][n] > 0)
					dust.push(make_pair(make_pair(m, n), room[m][n]));
			}
		}
		spread();
		clean();
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0)
				ans += room[i][j];
		}
	}

	cout << ans << endl;

	return 0;
}
