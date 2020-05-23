#include <bits/stdc++.h>

using namespace std;

#define MAX 50

int T, N, M, R, C, L, ans;
int pipe[MAX][MAX];
int visit[MAX][MAX];

queue<pair<int, int>> q;

int dx[] = { -1, 0, 1, 0 }; //상,우,하,좌
int dy[] = { 0, 1, 0, -1 }; //0,1,2,3

bool isRange(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M)
		return true;
	else
		return false;
}

void bfs() {

	// 초기 값
	q.push(make_pair(R, C));
	visit[R][C] = true;
	int time = 0;

	while (true) {
		time++;
		int size = q.size();

		if (time == L) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (visit[i][j] == true)
						ans++;
				}
			}
			break;
		}

		// 이전 큐 사이즈만큼 반복
		for (int s = 0; s < size; s++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			// 현재 파이프 번호
			int pipeNum = pipe[r][c];

			for (int i = 0; i < 4; i++) {
				// 현재 파이프에서 갈 수 없는 경우
				if (pipeNum == 2 && (i == 1 || i == 3))
					continue;
				else if (pipeNum == 3 && (i == 0 || i == 2))
					continue;
				else if (pipeNum == 4 && (i == 2 || i == 3))
					continue;
				else if (pipeNum == 5 && (i == 0 || i == 3))
					continue;
				else if (pipeNum == 6 && (i == 0 || i == 1))
					continue;
				else if (pipeNum == 7 && (i == 1 || i == 2))
					continue;

				int nx = r + dx[i];
				int ny = c + dy[i];
				int nextPipeNum = pipe[nx][ny]; //다음지점의 파이프종류

				// 범위, 방문 여부, 파이프 존재 여부
				if (isRange(nx, ny) && !visit[nx][ny] && pipe[nx][ny] != 0) {
					// 각 상, 우, 하, 좌 방향에
					// 다음에 올 수 있는 파이프 번호
					if (i == 0) {
						if (nextPipeNum == 1 || nextPipeNum == 2
								|| nextPipeNum == 5 || nextPipeNum == 6) {
							visit[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					} else if (i == 1) {
						if (nextPipeNum == 1 || nextPipeNum == 3
								|| nextPipeNum == 6 || nextPipeNum == 7) {
							visit[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					} else if (i == 2) {
						if (nextPipeNum == 1 || nextPipeNum == 2
								|| nextPipeNum == 4 || nextPipeNum == 7) {
							visit[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					} else if (i == 3) {
						if (nextPipeNum == 1 || nextPipeNum == 3
								|| nextPipeNum == 4 || nextPipeNum == 5) {
							visit[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}

int main() {
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		memset(pipe, 0, sizeof pipe);
		memset(visit, 0, sizeof visit);
		ans = 0;

		while (!q.empty())
			q.pop();

		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> pipe[i][j];
			}
		}

		bfs();

		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}
