#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000001

int N;
int num[11];
int op[4];
int ansMin = MAX, ansMax = -MAX;

// +-*/ 사용 개수, 현재 값 , 다음 인덱스, 연산횟수
void dfs(int pl, int mi, int mul, int div, int cur, int nidx, int cnt) {
	// 연산 횟수와 연산자 개수가 같은 경우
	if (cnt == N - 1) {
		ansMin = (ansMin > cur) ? cur : ansMin;
		ansMax = (ansMax < cur) ? cur : ansMax;
	}
	if (pl < op[0])
		dfs(pl + 1, mi, mul, div, cur + num[nidx], nidx + 1, cnt + 1);
	if (mi < op[1])
		dfs(pl, mi + 1, mul, div, cur - num[nidx], nidx + 1, cnt + 1);
	if (mul < op[2])
		dfs(pl, mi, mul + 1, div, cur * num[nidx], nidx + 1, cnt + 1);
	if (div < op[3])
		dfs(pl, mi, mul, div + 1, cur / num[nidx], nidx + 1, cnt + 1);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(0, 0, 0, 0, num[0], 1, 0);

	cout << ansMax << endl;
	cout << ansMin << endl;
}
