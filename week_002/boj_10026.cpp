#include <bits/stdc++.h>

using namespace std;

#define MAX 100

string arr[MAX][MAX];
bool visit[MAX][MAX];
int N;
int normal, abnormal;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		// 다음 위치
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 범위 체크
		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			// 방문 여부 체크, 같은 색인지 체크
			if (!visit[nx][ny] && arr[x][y] == arr[nx][ny])
				dfs(nx, ny);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;

		for (int j = 0; j < N; j++) {
			arr[i][j] = tmp[j];
		}
	}

	// 정상 구역
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 체크 안한 곳이면
			if (!visit[i][j]) {
				normal++;
				dfs(i, j);
			}
		}
	}
	cout << normal << endl;

	// visit 배열 초기화
	// G인 원소를 R로 변경
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
			if (arr[i][j] == "G")
				arr[i][j] = "R";
		}
	}

	// 색맹 구역
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 체크 안한 곳이면
			if (!visit[i][j]) {
				abnormal++;
				dfs(i, j);
			}
		}
	}
	cout << abnormal << endl;
}
