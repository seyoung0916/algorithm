#include <bits/stdc++.h>

using namespace std;

int N, L;
int arr[100][100];
int ans = 0;

bool check(vector<int> v) {
	int cur = v[0]; // 시작 높이
	int cnt = 1; // 현재 높이 연속 개수
	bool under = false; // 아래에 경사로를 놓아야 할 떄 쓰는 flag

	for (int i = 1; i < v.size(); i++) {

		int next = v[i];

		// 아래로 가는 경사로 놓아야 하는 상황에서 다음 높이가 다르면
		if (under && cur != next)
			return false;

		// cnt : 0은 현재 위치에 경사로를 놓은 것(내려가는 방향)
		if (under && cnt == 0 && next != cur)
			return false;

		if (cur == next) {
			cnt++;
		} else if (next < cur) { // 아래로 가야하는 경우
			if (next == cur - 1) { // 한 칸 낮은 높이
				cnt = 1;
				under = true;
			} else
				return false;
		} else { // 다음 높이가 현재보다 높은 경우
			if (next == cur + 1) {
				if (cnt >= L) { // 현재 높이 연속 개수가 경사로 길이보다 같거나 커야 경사로 놓을 수 있음
					cnt = 1; // 개수 리셋
				} else
					return false;
			} else
				return false; // 다음 높이가 2이상 차이남
		}

		cur = next;

		if (under) {
			if (cnt == L) {
				cnt = 0; // 경사로 놓음
				under = false;
			} else if (i == v.size() - 1) { // 경사로를 못 놓는 경우
				return false;
			}

		}

	}
	return true;
}
int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		vector<int> v;

		// 왼 > 오른
		for (int j = 0; j < N; j++) {
			v.push_back(arr[i][j]);
		}
		if (check(v)) { // 이동 가능한 경로면
			ans++;
		}

		v.clear();

		// 위 > 아래
		for (int j = 0; j < N; j++) {
			v.push_back(arr[j][i]);
		}
		if (check(v)) { // 이동 가능한 경로면
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
