#include <bits/stdc++.h>

using namespace std;

#define MAX 11

int ans;
int N, M, K;
int farm[MAX][MAX], food[MAX][MAX];
vector<int> tree[MAX][MAX];

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void year() {
	// 봄 & 여름
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			// 나무 나이 저장
			vector<int> tmp;
			// 죽은 나무 나이의 양분
			int deadFood = 0;
			// 나이 순 정렬
			sort(tree[i][j].begin(), tree[i][j].end());

			if (farm[i][j] == 0)
				continue;

			// 구역의 나무 개수만큼 반복
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];

				cout << "age " << age << endl;
				if (farm[i][j] >= age) {
					farm[i][j] -= age;
					tmp.push_back(age + 1); // 한 살 먹음
				} else {
					deadFood += age / 2;
				}
			}
			// 기존 나무 다 지우고 새 나무 나이 넣음
			tree[i][j].clear();
			for (int k = 0; k < tmp.size(); k++) {
				tree[i][j].push_back(tmp[k]);
			}

			// 여름
			farm[i][j] += deadFood;
		}
	}

	// 가을
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				// 나무의 나이가 5의 배수이면 1살 나무 주변에 추가
				if (tree[i][j][k] % 5 == 0) {
					for (int m = 0; m < 8; m++) {
						int nx = i + dx[m];
						int ny = j + dy[m];

						if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}

	// 겨울
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			farm[i][j] += food[i][j];
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> food[i][j];
			farm[i][j] = 5; // 처음 양분은 5
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		tree[x][y].push_back(z);
	}

	for (int i = 1; i <= K; i++) {
		year();
	}
	// 나무 계산
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += tree[i][j].size();
		}
	}

	cout << ans << endl;

	return 0;
}
