#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int r, c, k, ans;
int R, C;
int arr[MAX][MAX] = { 0 };

bool mySort(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
		else
			return false;
	} else
		return false;
}

void rotate() {
	int tmp[MAX][MAX];
	memmove(tmp, arr, sizeof arr);
	// 행<->열
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[j][i] = tmp[i][j];
		}
	}
}
void operation() {
	int tmpCol = C;

	for (int i = 0; i < R; i++) {
		map<int, int> m;
		vector<pair<int, int>> v;
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 0) // 0은 셈x
				continue;
			// 수, 등장횟수 세기
			m[arr[i][j]]++;
		}

		memset(arr[i], 0, sizeof arr[i]);

		// 벡터에 넣어 정렬
		for (auto it = m.begin(); it != m.end(); it++) {
			v.push_back(make_pair(it->first, it->second));
		}
		sort(v.begin(), v.end(), mySort);

		int idx = 0;
		for (int j = 0; j < v.size(); j++) {
			arr[i][idx] = v[j].first;
			idx++;
			arr[i][idx] = v[j].second;
			idx++;

		}
		tmpCol = (tmpCol < v.size() * 2) ? v.size() * 2 : tmpCol;
		m.erase(m.begin(), m.end());
	}
	C = tmpCol;
}

int main() {
	cin >> r >> c >> k;
	R = C = 3; // 초기 행,열 개수

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		if (arr[r - 1][c - 1] == k || ans > 100) {
			break;
		}
		if (R >= C) {
			operation();
		} else {
			rotate();
			int tmp = R;
			R = C;
			C = tmp;
			operation();
			rotate();
			//행 개수 <-> 열 개수
			tmp = R;
			R = C;
			C = tmp;
		}
		ans++;
	}

	if (ans > 100)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}
