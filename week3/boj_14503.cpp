#include <bits/stdc++.h>

using namespace std;

#define MAX 50

int N, M;
int r, c, d;
int arr[MAX][MAX];
bool check[MAX][MAX];
int ans = 0;
bool flag;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void solution() {

	// x, y 좌표, 방향, 현재에서 회전 횟수
	queue<pair<pair<int, int>, int>> q;

	// 현위치 청소
	check[r][c] = true;
	ans++;
	q.push(make_pair(make_pair(r, c), d));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;

		//q.pop();
		//cout << "====================" << endl;
		//cout << "ans " << ans << endl;
		//cout << "x " << x << " y " << y << " dir " << dir << endl;

		flag = false; // 청소 여부 체크
		// 왼쪽부터 체크
		for (int i = 1; i <= 4; i++) {
			// 다음 방향
			int ndir = (dir - i + 4) % 4;
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];

			// 범위 체크
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (!check[nx][ny] && arr[nx][ny] == 0) { // 청소 가능
				check[nx][ny] = true;
				ans++;
				q.push(make_pair(make_pair(nx, ny), ndir));
				flag = true;
				break;
			}
		}

		if (!flag) { // 청소 못한 경우
			// 후진을 위한 좌표
			int bdir = (dir + 2) % 4;
			int bx = x + dx[bdir];
			int by = y + dy[bdir];

			if (bx < 0 || bx >= N || by < 0 || by >= M)
				break;
			// 벽이면 후진 불가, 종료
			if (arr[bx][by] == 1)
				break;

			q.push(make_pair(make_pair(bx, by), dir));
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	solution();
	cout << ans << endl;
}
