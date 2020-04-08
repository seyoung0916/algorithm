#include <bits/stdc++.h>

using namespace std;

char arr[12][6];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int ans = 0;
int cnt, ret; // 문자 구역 개수, ret값 저장
vector<pair<int, int>> v;
bool flag = true; // 연속을 위한 flag
bool visit[12][6];

void printArr() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void down(int x, int y) {
	// y열을 한 칸 내림
	for (int i = x; i >= 0; i--) {
		arr[i + 1][y] = arr[i][y];
	}
	// 맨 위 .으로 채움
	arr[0][y] = '.';
}

void dfs(int x, int y) {
	cnt++;
	char ch = arr[x][y];
	visit[x][y] = true;
	v.push_back(make_pair(x, y));
	//cout << "x " << x << " y " << y << " cnt " << cnt << endl;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
			continue;
		if (arr[nx][ny] == ch && !visit[nx][ny]) { // 같은 문자이면
			dfs(nx, ny);
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	while (flag) {
		int tmp = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				// 4개 이상인 것 터트리기
				if (arr[i][j] != '.') {
					cnt = 0, ret = 0;
					memset(visit, false, sizeof(visit));
					dfs(i, j);

					// 4개 이상 모여있으면
					if (cnt >= 4) {
						for (int k = 0; k < v.size(); k++) {
							int x = v[k].first;
							int y = v[k].second;
							arr[x][y] = '.';

							// 터트리면 증가시켜 flag 나중에 변환
							tmp++;
						}
					}
					v.clear();
				}
			}
		}

		if (tmp > 0) {
			flag = true; // 터진 경우가 있으면 flag true로
			ans++;
		} else {
			flag = false;
		}

		//printArr();

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && arr[i + 1][j] == '.') {
					//cout << "i " << i << " j " << j << endl;
					down(i, j);
				}
			}
		}
		//printArr();
	}
	cout << ans << endl;
}
