#include <bits/stdc++.h>

using namespace std;

#define MAX 20
#define dessert 101

int T, N, ans;
int Sx, Sy, cnt;
int arr[MAX][MAX];
bool dCheck[dessert];
bool arrCheck[MAX][MAX];

// 시계방향
int dx[] = { 1, 1, -1, -1 };
int dy[] = { 1, -1, -1, 1 };

void dfs(int x, int y, int d, int cnt) {

	//cout << x << " , " << y << " cnt : " << cnt << endl;

	// 처음 들어온 위치와 디저트 개수 true
	dCheck[arr[x][y]] = true;
	arrCheck[x][y] = true;

	// 시작점으로 돌아왔을 경우
	if (x == Sx && y == Sy && cnt > 1) {
		ans = (ans < cnt) ? cnt : ans;
		//cout << "------------ " << ans << endl;
		return;
	}

	// 기존 방향, 90도 방향 두가지
	for (int i = 0; i < 2; i++) {
		// 시작 점에서는 오른쪽 아래로만 감
		if (x == Sx && y == Sy && i == 1)
			continue;
		int nd = (d + i) % 4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];

		// 범위 내이고 다음 x값이 시작점보다 크거나 같아야 함
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && nx >= Sx) {
			if (!dCheck[arr[nx][ny]] && !arrCheck[nx][ny]) {
				arrCheck[nx][ny] = true;
				dCheck[arr[nx][ny]] = true;

				dfs(nx, ny, nd, cnt + 1);

				arrCheck[nx][ny] = false;
				dCheck[arr[nx][ny]] = false;
			} else if (nx == Sx && ny == Sy) {
				dfs(nx, ny, nd, cnt + 1);
			}
		}
	}
}

int main() {

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		memset(arr, 0, sizeof arr);

		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		ans = -1;
		memset(dCheck, 0, sizeof dCheck);
		memset(arrCheck, 0, sizeof arrCheck);

		// i, j는 시작할 수 있는 범위
		for (int i = 0; i <= N - 2; i++) {
			for (int j = 1; j <= N - 2; j++) {

				memset(dCheck, 0, sizeof dCheck);
				memset(arrCheck, 0, sizeof arrCheck);

				Sx = i;
				Sy = j;

				//cout << " sx " << Sx << " Sy " << Sy << endl;

				dfs(i, j, 0, 0);
			}
		}

		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}
