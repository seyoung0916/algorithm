#include <bits/stdc++.h>

using namespace std;

int arr[4][8];
int K; // 회전 횟수
int dir[4];
int ans;

void rotate(int x, int d) {
	int tmp[8];
	if (d == 1) {
		// 임시 배열에 시계 방향으로 넣음
		for (int i = 0; i < 7; i++) {
			tmp[i + 1] = arr[x][i];
		}
		tmp[0] = arr[x][7];

		// arr에 넣음
		for (int i = 0; i < 8; i++) {
			arr[x][i] = tmp[i];
		}
	} else if (d == -1) {
		// 임시 배열에 반시계 방향으로 넣음
		for (int i = 1; i < 8; i++) {
			tmp[i - 1] = arr[x][i];
		}
		tmp[7] = arr[x][0];

		// arr에 넣음
		for (int i = 0; i < 8; i++) {
			arr[x][i] = tmp[i];
		}
	}
}
void solve(int a, int b) {
	memset(dir, 2, sizeof dir); // 회전 안 정해진 상태
	bool visit[4];
	queue<int> q;

	dir[a - 1] = b; // a-1 톱니의 회전 방향

	q.push(a - 1);

	while (!q.empty()) {
		int cur = q.front();
		visit[cur] = true;
		q.pop();

		int nx = cur + 1;
		if (nx >= 0 && nx < 4 && !visit[nx]) {
			int l = arr[cur][2];
			int r = arr[nx][6];

			if (l != r) // 다르면 반대 방향으로 회전
				dir[nx] = dir[cur] * -1;
			else
				dir[nx] = 0;
			q.push(nx);
		}

		nx = cur - 1;
		if (nx >= 0 && nx < 4 && !visit[nx]) {
			int l = arr[cur][6];
			int r = arr[nx][2];

			if (l != r) // 다르면 반대 방향으로 회전
				dir[nx] = dir[cur] * -1;
			else
				dir[nx] = 0;
			q.push(nx);
		}
	}
	for (int i = 0; i < 4; i++) {
		rotate(i, dir[i]);
	}
}

int main() {
	string tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;

		for (int j = 0; j < 8; j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;

		solve(a, b);
	}

	// 점수 계산
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1)
			ans += pow(2, i);
	}
	cout << ans << endl;
	return 0;
}
