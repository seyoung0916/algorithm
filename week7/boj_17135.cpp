#include <bits/stdc++.h>

using namespace std;

#define MAX 15

int N, M, D, ans = 0;
int arr[MAX][MAX];
vector<int> v; // 궁수
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
		vector<int> target;
		for (int i = 0; i < v.size(); i++) {
			// 궁수 좌표
			int x = N;
			int y = v[i];

			int idx = 0;
			int ey = enemy[0].second;
			int ed = abs(x - enemy[0].first) + abs(y - enemy[0].second);

			for (int j = 1; j < enemy.size(); j++) {
				int tmpD = abs(x - enemy[j].first) + abs(y - enemy[j].second);

				// 더 가까움
				if (ed > tmpD) {
					ey = enemy[j].second;
					ed = tmpD;
					idx = j;
				} else if (tmpD == ed && ey > enemy[j].second) {
					// 거리 같고 더 왼쪽
					ey = enemy[j].second;
					idx = j;
				}
			}

			if (ed <= D) {
				target.push_back(idx);
			}
		}

		// 중복 적 제거
		target.erase(unique(target.begin(), target.end()), target.end());
		sort(target.begin(), target.end());
		int shoot = 0; // erase 하면 한 칸씩 뒤로 밀어서 지워야 함
		for (int i = 0; i < target.size(); i++) {
			enemy.erase(enemy.begin() + (target[i] - shoot++));
			cnt++;
		}

		if (enemy.empty())
			break;
		vector<pair<int, int>> copyTemp;
		for (int i = 0; i < enemy.size(); i++) {
			if (enemy[i].first < N - 1) {
				copyTemp.push_back(
						make_pair(enemy[i].first + 1, enemy[i].second));
			}
		}
		enemy = copyTemp;

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
		vector<pair<int, int>> tmpEnemy;
		v.clear();
		tmpEnemy = enemy;

		for (int i = 0; i < M; i++) {
			if (perm[i] == 1) { // 궁수의 위치
				v.push_back(i);
			}
		}

		solve();
		enemy = tmpEnemy;
	} while (next_permutation(perm.begin(), perm.end()));

	cout << ans << endl;
	return 0;
}
