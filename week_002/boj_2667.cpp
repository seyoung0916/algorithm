#include <bits/stdc++.h>

using namespace std;

#define MAX 25
/*
 7
 0110100
 0110101
 1110101
 0000111
 0100000
 0111110
 0111000
 */

int N;
int cnt; // 단지 개수
int num;
int arr[MAX][MAX];
bool visit[MAX][MAX];
vector<int> v;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
	num++;

	visit[x][y] = true;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (arr[nx][ny] && !visit[nx][ny])
				dfs(nx, ny);
		}
	}
}

int boj_2667() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)
			arr[i][j] = temp[j] - '0';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			num = 0;
			// 집이 있는 공간 && 방문 체크 안된 곳
			if (arr[i][j] && !visit[i][j]) {
				cnt++; // 단지수 추가
				// dfs 돌리기
				dfs(i, j);
				v.push_back(num);
			}
		}
	}
	cout << cnt << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	/*
	 // 출력
	 for (int i = 0; i < N; i++) {
	 for (int j = 0; j < N; j++) {
	 cout << arr[i][j] << " ";
	 }
	 cout << endl;
	 }*/
}
