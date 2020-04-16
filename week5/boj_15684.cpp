#include <bits/stdc++.h>

using namespace std;

int N, M, H, ledder;
bool res;
bool visit[31][11];
int ans = 987654321;
/*
 // 사다리 출력
 void printArr() {
 cout << "----" << endl;
 for (int i = 1; i <= H; i++) {
 for (int j = 1; j <= N; j++) {
 cout << visit[i][j] << " ";
 }
 cout << endl;
 }
 cout << "----" << endl;
 }
 */

bool check() {

	for (int i = 1; i <= N; i++) {
		int cur = i; // i에서 시작

		for (int j = 1; j <= H; j++) {
			if (visit[j][cur] == true)
				cur += 1; // 오른쪽으로 이동
			else if (cur - 1 > 0 && visit[j][cur - 1] == true)
				cur -= 1; // 왼쪽으로
		}
		if (cur != i)
			return false; // 시작과 끝값 다르면 x
	}
	res = true;
	return true;
}

void dfs(int idx, int cnt) {
	//printArr();
	if (cnt == ledder) { // 종료 조건
		if (check()) {
			ans = (ans > cnt) ? cnt : ans;
		}
		return;
	}

	// idx 행부터 사다리를 그음
	for (int i = idx; i <= H; i++) {
		// N-1에서까지만 사다리를 그을 수 있음
		for (int j = 1; j < N; j++) {
			if (!visit[i][j]) {
				// 연속되지 않게 그릴 수 있을 경우
				if (!visit[i][j - 1] && !visit[i][j + 1]) {
					visit[i][j] = true;
					dfs(i, cnt + 1);
					visit[i][j] = false;
				}
			}
		}
	}
}

int main() {
	int a, b;
	cin >> N >> M >> H;

	if (M == 0) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		visit[a][b] = true;
	}

	for (int i = 0; i <= 3; i++) {
		ledder = i;
		dfs(1, 0);
	}

	ans = (ans == 987654321) ? -1 : ans;
	cout << ans << endl;

	return 0;
}
