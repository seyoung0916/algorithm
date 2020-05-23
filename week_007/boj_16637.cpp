#include <bits/stdc++.h>

using namespace std;

#define MAX 19

int N, opNum, ans = -987654321;
int num[MAX], op[MAX];

int cal(int N1, char op, int N2) {
	if (op == '+')
		return N1 + N2;
	else if (op == '-')
		return N1 - N2;
	else
		return N1 * N2;
}

void dfs(int idx, int res) {
	//cout << idx << "   res " << res << endl;

	if (idx >= opNum) {
		ans = max(ans, res);
		return;
	}

	// 현재 연산자에 괄호 추가
	int curRes = cal(res, op[idx], num[idx + 1]);

	dfs(idx + 1, curRes);

	if (idx + 1 < opNum) {
		// 다음 연산자에 괄호 추가
		int afterRes = cal(num[idx + 1], op[idx + 1], num[idx + 2]);
		int curRes = cal(res, op[idx], afterRes);
		dfs(idx + 2, curRes);
	}
}

int main() {

	string ex;
	cin >> N;
	cin >> ex;

	int idx1 = 0, idx2 = 0;
	for (int i = 0; i < N; i++) {
		// 수, 연산자 구별
		if (i % 2 == 0)
			num[idx1++] = ex[i] - '0';
		else
			op[idx2++] = ex[i];
	}
	opNum = N / 2;

	dfs(0, num[0]);

	cout << ans << endl;
	return 0;
}
