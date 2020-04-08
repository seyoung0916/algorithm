#include <bits/stdc++.h>

using namespace std;

#define MAX 8

int N, M;
int arr[MAX][MAX];
vector<pair<int, int>> cam;
int camNum;
int ans = 987654321;

// 위 오른 아래 왼
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// 출력
void printArr() {
	cout << "printArr() =====" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "============" << endl;
}

// 카메라가 감시가능한 범위 -1로 바꿈
void watch(int x, int y, int n) {
	int nx = x;
	int ny = y;
	while (1) {
		nx = nx + dx[n];
		ny = ny + dy[n];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (arr[nx][ny] == 6)
				break;
			if (arr[nx][ny] == 0)
				arr[nx][ny] = -1;
		} else
			break;
	}
}

void solution(int idx) {

	if (idx == camNum) {
		//cout << "end condition" << endl;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0)
					cnt++;
			}
		}
		ans = (ans > cnt) ? cnt : ans;
		return;
	}

	// 원래 arr를 tmp에 임시 저장
	int tmp[MAX][MAX];
	int x = cam[idx].first;
	int y = cam[idx].second;

	if (arr[x][y] == 1) { // 1번
		for (int i = 0; i < 4; i++) {
			memmove(tmp, arr, sizeof(arr));
			watch(x, y, i);
			//printArr();
			solution(idx + 1);
			memmove(arr, tmp, sizeof(tmp));
		}
	} else if (arr[x][y] == 2) { // 2번
		for (int i = 0; i < 2; i++) {
			memmove(tmp, arr, sizeof(arr));
			watch(x, y, i);
			watch(x, y, i + 2);
			//printArr();
			solution(idx + 1);
			memmove(arr, tmp, sizeof(tmp));
		}
	} else if (arr[x][y] == 3) { // 3번
		for (int i = 0; i < 4; i++) {
			memmove(tmp, arr, sizeof(arr));
			watch(x, y, i);
			watch(x, y, (i + 1) % 4);
			//printArr();
			solution(idx + 1);
			memmove(arr, tmp, sizeof(tmp));
		}
	} else if (arr[x][y] == 4) { // 4번
		for (int i = 0; i < 4; i++) {
			memmove(tmp, arr, sizeof(arr));
			// < ^ > 시계방향으로 네 번 탐색
			watch(x, y, (i - 1 + 4) % 4);
			watch(x, y, i);
			watch(x, y, (i + 1) % 4);
			//printArr();
			solution(idx + 1);
			memmove(arr, tmp, sizeof(tmp));
		}
	} else { // 5번
		memmove(tmp, arr, sizeof(arr));
		// 전 방향 탐색
		watch(x, y, 0);
		watch(x, y, 1);
		watch(x, y, 2);
		watch(x, y, 3);
		//printArr();
		solution(idx + 1);
		memmove(arr, tmp, sizeof(tmp));
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cam.push_back(make_pair(i, j));
			}
		}
	}

	camNum = cam.size();

	solution(0);
	cout << ans << endl;
	return 0;
}
