#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

// 전체층, 사무실, 현재, u횟수, d횟수
int F, S, G, U, D;
int upCnt, downCnt;
bool visit[1000001];
int ans = MAX;

// 현재 층, cnt
queue<pair<int, int>> q;

int main() {
	cin >> F >> S >> G >> U >> D;

	int dx[] = { U, D * -1 };

	// 첫 데이터 넣음
	// S층에서 시작, 카운트 0
	q.push(make_pair(S, 0));
	visit[S] = true;

	while (!q.empty()) {
		pair<int, int> floorInfo = q.front();
		q.pop();

		// 목표 층 도달
		if (floorInfo.first == G) {
			ans = (ans > floorInfo.second) ? floorInfo.second : ans;
			break;
		}

		for (int i = 0; i < 2; i++) {
			int nx = floorInfo.first + dx[i]; // 다음 층

			if (nx >= 1 && nx <= F) {
				if (!visit[nx]) {
					visit[nx] = true;
					q.push(make_pair(nx, floorInfo.second + 1));
				}
			}
		}
	}
	if (ans == MAX)
		cout << "use the stairs";
	else
		cout << ans;
	return 0;
}
