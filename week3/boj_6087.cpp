#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100

int W, H;
char arr[MAX][MAX];
int visit[MAX][MAX];
pair<int, int> start, finish;
int ans = 987654321;

// 상 하 좌 우
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void solution() {

	// 현재 좌표 x, y + 방향(상하좌우), 거울 개수
	queue<pair<pair<int, int>, pair<int, int>>> q;

	for (int i = 0; i < 4; i++) {
		// 시작점, 상하좌우, 이때 거울 필요x
		q.push(
				make_pair(make_pair(start.first, start.second),
						make_pair(i, 0)));
	}
	visit[start.first][start.second] = 0;

	while (!q.empty()) {
		//cout << "ans " << ans << endl;
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		/*cout << "x " << x << " y " << y << " i " << dir << " cnt " << cnt
				<< endl;
		cout << visit[x][y] << endl;*/
		if (x == finish.first && y == finish.second) {
			ans = (ans > cnt) ? cnt : ans;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ndir = i;
			int ncnt = cnt; // 다음 거울 개수

			// 범위
			if (nx < 0 || nx >= H || ny < 0 || ny >= W)
				continue;
			// 장애물
			if (arr[nx][ny] == '*')
				continue;
			// 이전 dir과 다르면 거울 개수 + 1
			if (dir != i)
				ncnt += 1;
			// 현재 거울 개수가 같거나 더 작을 경우 값 갱신
			// 같은 경우에도 넣어줘야 상하좌우 방향에 대해서 다 push 할 수 있음
			if (visit[nx][ny] >= ncnt) {
				visit[nx][ny] = ncnt;
				/*cout << "nx " << nx << " ny " << ny << " i " << i << " ncnt "
						<< ncnt << endl;*/
				q.push(make_pair(make_pair(nx, ny), make_pair(i, ncnt)));
			}
		}
		//cout << "====" << endl;
	}
}

int main() {
	int cnt = 0;
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
			visit[i][j] = 987654321; // 거울 개수 최대로 초기화

			// 시작, 끝 저장
			if (arr[i][j] == 'C') {
				if (cnt == 0) {
					start.first = i;
					start.second = j;
					cnt++;
				} else {
					finish.first = i;
					finish.second = j;
				}

			}
		}
	}

	solution();

	cout << ans << endl;

	return 0;
}
