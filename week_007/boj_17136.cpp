#include <bits/stdc++.h>

using namespace std;

#define MAX 10

int arr[MAX][MAX];
int ans = 987654321;
int paper[6] = { 0, 5, 5, 5, 5, 5 };

void dfs(int x, int y, int cnt) {
	//cout << "x " << x << " y " << y << " cnt " << cnt << endl;
	// 다음줄 확인
	if (y == MAX) {
		dfs(x + 1, 0, cnt);
		return;
	}
	// 마지막 줄
	if (x == MAX) {
		ans = (ans > cnt) ? cnt : ans;
		//cout << "----------------" << endl;
		return;
	}
	if (arr[x][y] == 0) {
		dfs(x, y + 1, cnt);
		return;
	}

	// 색종이 크기
	for (int len = 5; len >= 1; len--) {
		int tmp[MAX][MAX];
		bool flag = true;

		if (paper[len] == 0 || x + len < MAX || y + len < MAX) {
			continue;
		}

		for (int m = 0; m < len; m++) {
			for (int n = 0; n < len; n++) {
				if (arr[x + m][y + n] == 0) { // 현재 크기로 덮을 수 없음
					flag = false;
					break;
				}
			}
			if (flag == false)
				break;
		}

		if (flag == false)
			continue;

		memmove(tmp, arr, sizeof tmp);

		// 색종이로 덮음
		//cout << x << " + " << y << " , " << len << "possible" << endl;
		for (int m = 0; m < len; m++) {
			for (int n = 0; n < len; n++) {
				arr[x + m][y + n] = 0;
			}
			if (flag == false)
				break;
		}

		paper[len]--;
		dfs(x, y + len, ++cnt);

		paper[len]++;
		cnt--;

		memmove(arr, tmp, sizeof tmp);
	}

}

int main() {
	int num = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				num++;
		}
	}

	if (num == 0) {
		cout << 0 << endl;
		return 0;
	} else if (num == MAX * MAX) {
		cout << 4 << endl;
		return 0;
	}

	dfs(0, 0, 0);

	if (ans == 987654321)
		ans = -1;
	cout << ans << endl;

	return 0;
}

