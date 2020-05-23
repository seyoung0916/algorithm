#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int N, K;
int ans = MAX;
int dx[3] = { -1, 1, 2 };
bool visit[MAX];
queue<pair<int, int>> q;

/*
5 17
*/

void bfs() {
	// 시작점, cnt를 위한 값 push
	q.push(make_pair(N, 0));
	visit[N] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		cout << p.first << " " << p.second << endl;
		q.pop();
		if (p.first == K) {
			ans = (ans > p.second) ? p.second : ans;
			break;
		}
		for (int i = 0; i < 3; i++) {
			// 인덱스가 2면 *2가 다음 위치
			int nx = (i == 2) ? p.first * dx[i] : p.first + dx[i];

			if (nx >= 0 && nx < MAX) {
				// 체크 안한 곳
				if (!visit[nx]) {
					visit[nx] = true;
					q.push(make_pair(nx, p.second + 1));
				}
			}
		}
	}

}

int main() {

	cin >> N >> K;

	bfs();

	cout << ans << endl;

	return 0;
}
