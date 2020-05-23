#include <bits/stdc++.h>

using namespace std;

#define MAX 16

int N, M, D, ans = 0;
int arr[MAX][MAX];
vector<pair<int, int>> enemy;

/*void print() {
	cout << "------" << endl;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}*/
void enemyMove() {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			// 한 칸 아래 이동
			arr[i + 1][j] = arr[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		arr[0][i] = 0;
	}
}

void solve() {
	int cnt = 0;
	while (!enemy.empty()) {
		for (int i = 0; i < M; i++) {
			if (arr[N][i] != 2) // 궁수X
				continue;
			// 제거할 적 정보를 담음
			int dx = -1, dy = -1;
			int tmpD = 987654321;
			for (int k = 0; k < enemy.size(); k++) {
				int ex = enemy[k].first;
				int ey = enemy[k].second;
				int ed = abs(N - ex) + abs(i - ey);

				if (ed <= D) {
					if (ed < tmpD) {
						dx = enemy[k].first;
						dy = ey;
						tmpD = ed;
					} else if (tmpD == ed) {
						if (ey > dy)
							continue;
						dx = ex;
						dy = ey;
					}
				}

			}
			if (dx != -1 && dy != -1 && arr[dx][dy] != 0) {
				// 적 제거
				arr[dx][dy] = 0;
				cnt++;
			}
		}
		enemyMove();
		enemy.clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j]==1)enemy.push_back(make_pair(i, j));
			}
		}
	}
	ans = (ans < cnt) ? cnt : ans;
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				enemy.push_back(make_pair(i, j));
		}
	}

	vector<int> perm;
	for (int i = 0; i < M; i++) {
		if (i < 3)
			perm.push_back(1);
		else
			perm.push_back(0);
	}
	sort(perm.begin(), perm.end());

	do {
		int tmp[MAX][MAX];
		vector<pair<int, int>> tmpEnemy;
		memmove(tmp, arr, sizeof tmp);
		tmpEnemy = enemy;

		for (int i = 0; i < M; i++) {
			if (perm[i] == 1) { // 궁수의 위치
				arr[N][i] = 2;
			}
		}

		solve();
		memmove(arr, tmp, sizeof tmp);
		enemy = tmpEnemy;
	} while (next_permutation(perm.begin(), perm.end()));

	cout << ans << endl;
	return 0;
}