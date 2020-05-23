#include <bits/stdc++.h>

using namespace std;

#define MAX 11

int N, ans = 987654321;
int population[MAX];
vector<int> gu[MAX];

bool check(vector<int> v) {

	if (v.size() == 0)
		return false;

	queue<int> q;
	// 방문 체크 > v의 원소가 하나라도 false면 안 이어진 것
	bool visit[MAX];
	memset(visit, false, sizeof visit);

	q.push(v[0]);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		visit[cur] = true;

		for (int i = 0; i < v.size(); i++) {
			if (find(gu[cur].begin(), gu[cur].end(), v[i]) != gu[cur].end()
					&& visit[v[i]] == false) {
				q.push(v[i]);
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (visit[v[i]] == false)
			return false;
	}
	return true;
}

int cal(vector<int> a, vector<int> b) {
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < a.size(); i++) {
		sum1 += population[a[i]];
	}
	for (int i = 0; i < b.size(); i++) {
		sum2 += population[b[i]];
	}

	return abs(sum1 - sum2);
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> population[i];
	}

	for (int i = 1; i <= N; i++) {
		int x, tmp;
		cin >> x;

		// i도시는 tmp 도시와 연결됨
		for (int j = 1; j <= x; j++) {
			cin >> tmp;
			gu[i].push_back(tmp);
		}
	}

	for (int i = 1; i <= N; i++) {
		sort(gu[i].begin(), gu[i].end());
	}

	for (int i = 1; i <= N; i++) {
		// 구역 i개 선택
		int num = i;
		vector<int> tmp;

		for (int k = 1; k <= N; k++) {
			if (k <= num)
				tmp.push_back(1);
			else
				tmp.push_back(0);
		}
		sort(tmp.begin(), tmp.end());

		do {
			vector<int> a, b;
			// a, b 구역 나눔
			for (int j = 0; j < tmp.size(); j++) {

				if (tmp[j] == 1)
					a.push_back(j + 1);
				else
					b.push_back(j + 1);
			}

			if (check(a) == false)
				continue;
			if (check(b) == false)
				continue;

			ans = min(ans, cal(a, b));
		} while (next_permutation(tmp.begin(), tmp.end()));
	}

	if (ans == 987654321)
		ans = -1;

	cout << ans << endl;
	return 0;
}
