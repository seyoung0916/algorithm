#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 201

int A, B, C;
bool visit[MAX][MAX][MAX];
vector<int> ans;

void solution() {

	queue<pair<pair<int, int>, int>> q;
	// 처음 값 push
	q.push(make_pair(make_pair(0, 0), C));

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		//cout << "a " << a <<" b " << b << " c " << c <<endl;

		if (visit[a][b][c])
			continue;
		//방문 처리
		visit[a][b][c] = true;

		if (a == 0)
			ans.push_back(c);

		// a->b
		// 두 물통 더한 값이 목표 물통 범위 내이면
		// a물통이 0
		if (a + b <= B)
			q.push(make_pair(make_pair(0, a + b), c));
		// 목표 물통 범위 넘으면
		// a물통은 a+b-목표물통 최대치
		else
			q.push(make_pair(make_pair(a + b - B, B), c));

		// a->c
		if (a + c <= C)
			q.push(make_pair(make_pair(0, b), a + c));
		else
			q.push(make_pair(make_pair(a + c - C, b), C));

		// b->c
		if (b + c <= C)
			q.push(make_pair(make_pair(a, 0), b + c));
		else
			q.push(make_pair(make_pair(a, b + c - C), C));

		// b->a
		if (b + a <= A)
			q.push(make_pair(make_pair(b + a, 0), c));
		else
			q.push(make_pair(make_pair(A, b + a - A), c));

		// c->a
		if (c + a <= A)
			q.push(make_pair(make_pair(c + a, b), 0));
		else
			q.push(make_pair(make_pair(A, b), c + a - A));

		// c->b
		if (c + b <= B)
			q.push(make_pair(make_pair(a, c + b), 0));
		else
			q.push(make_pair(make_pair(a, B), c + b - B));

	}
}

int main() {
	cin >> A >> B >> C;

	solution();

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
