#include <bits/stdc++.h>

using namespace std;

#define MAX 101

// 상어 정보
struct sharkInfo {
	int x;
	int y;
	int speed;
	int direct;
	int size;
};

int R, C, M;
vector<int> arr[MAX][MAX];
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };
vector<sharkInfo> shark;
int ans;

// 상어 사이즈로 내림차순
bool compare(int a, int b) {
	if (shark[a].size > shark[b].size)
		return true;
	else
		return false;
}

void fishing(int i) {
	for (int j = 1; j <= R; j++) {
		if (arr[j][i].size() != 0) {
			// 잡은 상어에 포함 + 그 구역의 상어 없앰
			int idx = arr[j][i][0];
			ans += shark[idx].size;
			arr[j][i].clear();
			shark[idx].size = 0;
			break;
		}
	}
}
void move() {

	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].size == 0)
			continue;
		int r = shark[i].x;
		int c = shark[i].y;
		// 상어 위치 바꾸기 전에 기존 위치를 없앰
		arr[r][c].clear();
	}

	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].size == 0)
			continue; // 죽은 상어

		int r = shark[i].x;
		int c = shark[i].y;
		int s = shark[i].speed;
		int d = shark[i].direct;

		if (d == 1 || d == 2) {
			int re = (R - 1) * 2; // 제자리로 오는 움직임 수
			// 제자리보다 큰 수를 움직이면 제자리만큼 빼고 움직이면 됨
			if (s >= re)
				s = s % re;

			for (int j = 0; j < s; j++) {
				int nx = r + dx[d];
				int ny = c + dy[d];

				if (nx < 1) {
					d = 2;
					nx += 2; // 방향을 돌려 한 칸 가야 함
				}
				if (nx > R) {
					d = 1;
					nx -= 2;
				}
				r = nx;
				c = ny;
			}
		} else {
			int re = (C - 1) * 2;
			if (s >= re)
				s = s % re;

			for (int j = 0; j < s; j++) {
				int nx = r + dx[d];
				int ny = c + dy[d];

				if (ny < 1) {
					d = 3;
					ny += 2; // 방향을 돌려 한 칸 가야 함
				}
				if (ny > C) {
					d = 4;
					ny -= 2;
				}
				r = nx;
				c = ny;
			}
		}
		// 상어 위치 정보 바꿔줌
		shark[i].x = r;
		shark[i].y = c;
		shark[i].direct = d;
		// 구역에 몇 번째 상어가 있는지 저장
		arr[r][c].push_back(i);
	}
}

void kill() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j].size() > 1) { // 상어 2마리 이상인 경우
				sort(arr[i][j].begin(), arr[i][j].end(), compare);
				int tmp = arr[i][j][0]; // 제일 큰 상어

				// 상어 죽임
				for (int k = 1; k < arr[i][j].size(); k++) {
					shark[arr[i][j][k]].x = -1;
					shark[arr[i][j][k]].y = -1;
					shark[arr[i][j][k]].size = 0;
				}

				arr[i][j].clear();
				arr[i][j].push_back(tmp);
			}
		}
	}
}

int main() {

	cin >> R >> C >> M;

	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		arr[r][c].push_back(i);
		shark.push_back( { r, c, s, d, z });
	}

	// 낚시왕이 C번 움직임
	for (int i = 1; i <= C; i++) {
		fishing(i);
		move();
		kill();
	}

	cout << ans << endl;

	return 0;
}
