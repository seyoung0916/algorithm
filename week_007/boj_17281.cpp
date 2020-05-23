#include <bits/stdc++.h>

using namespace std;

#define MAX 50
#define PLAYER 10

int N, ans = 0;
int arr[MAX][PLAYER];
int order[PLAYER];
bool selected[PLAYER];
int num = 0;

void play() {
	int score = 0, start = 1;
	int base[4];

	// N이닝동안 진행
	for (int i = 0; i < N; i++) {
		int out = 0;
		bool nextIning = false;
		memset(base, 0, sizeof base);

		while (true) {

			for (int p = start; p < PLAYER; p++) {
				// 현재 선수와 능력
				int player = order[p];
				int ability = arr[i][player];

				if (ability == 0) {
					out++;
				} else if (ability == 1) {
					for (int k = 3; k >= 1; k--) { // 3루부터 한 루씩 전진
						if (base[k] == 1) { // 루에 사람이 있을 경우
							if (k == 3) { // 3루에 사람 있을 경우
								score++;
								base[k] = 0;
							} else {
								base[k + 1] = 1;
								base[k] = 0;
							}
						}

					}
					base[1] = 1; // 1루에 타자 들어감
				} else if (ability == 2) {
					for (int k = 3; k >= 1; k--) {
						if (base[k] == 1) {
							if (k == 3 || k == 2) {
								score++;
								base[k] = 0;
							} else {
								base[k + 2] = 1;
								base[k] = 0;
							}
						}
					}
					base[2] = 1; // 타자 2루로
				} else if (ability == 3) {
					for (int k = 3; k >= 1; k--) {
						if (base[k] == 1) {
							score++;
							base[k] = 0;
						}
					}
					base[3] = 1; // 타자 3루로
				} else {
					for (int k = 1; k <= 3; k++) {
						if (base[k] == 1) {
							score++;
							base[k] = 0;
						}
					}
					score++; // 타자
				}

				if (out == 3) {
					start = p + 1;
					if (start == PLAYER)
						start = 1;
					nextIning = true;
					break;
				}
			}
			if (nextIning)
				break;
			start = 1;
		}
	}
	//cout << "score " << score << endl;
	ans = max(ans, score);
}

void dfs(int cnt) {
	if (cnt == PLAYER) {
		play();
		return;
	}

	for (int i = 1; i < PLAYER; i++) {
		if (selected[i] == true)
			continue;
		order[i] = cnt;
		selected[i] = true;
		dfs(cnt + 1);
		selected[i] = false;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> arr[i][j];
		}
	}

	// 타순 정하기
	order[4] = 1;
	selected[4] = true;
	dfs(2);

	cout << ans << endl;
	return 0;
}
