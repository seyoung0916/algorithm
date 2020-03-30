#include <bits/stdc++.h>

using namespace std;

#define MAX 20
int N, M, X, Y, K; // N*M, K개 명령
int arr[20][20];
int cmd[1000];
int dice[7]; //위, 아래, 왼, 오, 앞, 뒤
int cur;

// 동서북남
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

void solution() {
	// 처음 주사위 윗면
	cur = 1;

	for (int i = 0; i < K; i++) {
		// 이동해야 할 위치
		int dir = cmd[i];

		int nx = X + dx[dir];
		int ny = Y + dy[dir];

		// 범위 체크
		if (nx >= 0 & nx < N && ny >= 0 && ny < M) {
			// 현재 위치 갱신
			X = nx;
			Y = ny;
			int tmp = dice[1]; // 맨 윗값 임시 저장
			// 주사위가 아닌 값들이 움직이기 때문에 맨 위는 항상 1번 면

			if (dir == 1) { // 동

				dice[1] = dice[4];
				dice[4] = dice[6];
				dice[6] = dice[3];
				dice[3] = tmp;
			} else if (dir == 2) { // 서

				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[6] = dice[4];
				dice[4] = tmp;
			} else if (dir == 3) { // 북

				dice[1] = dice[5];
				dice[5] = dice[6];
				dice[6] = dice[2];
				dice[2] = tmp;
			} else if (dir == 4) { // 남

				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[6] = dice[5];
				dice[5] = tmp;
			}
		} else {
			continue;
		}

		// 현재 위치의 값이 0이면 주사위의 바닥면 복사
		if (arr[X][Y] == 0) {
			arr[X][Y] = dice[6];
		} else { // 0이 아닌 경우
			//칸의 수가 주사위 바닥으로 복사
			dice[6] = arr[X][Y];
			// 칸의 수는 0으로 바뀜
			arr[X][Y] = 0;
		}

		cout << dice[1] << endl;
	}
}

int main() {
	cin >> N >> M >> X >> Y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}

	int tmp;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		cmd[i] = tmp;
	}

	solution();

	return 0;
}
