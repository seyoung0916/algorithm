#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int n;
bool arr[MAX][MAX];
int visit[MAX];
queue<int> q;
vector<int> blue, red;

void solution() {

	/*for (int i = 1; i <= n; i++) {
	 // 이미 팀이 정해진 경우
	 if (visit[i] != 0)
	 continue;

	 visit[i] = 1; // 팀 배정

	 for (int j = 1; j <= n; j++) {
	 if (visit[j] != 0)
	 continue;
	 if (arr[i][j] == false)
	 visit[j] = visit[i] * -1;
	 }
	 }
	 */
	for (int i = 1; i <= n; i++) {
		// 이미 팀이 정해진 경우
		if (visit[i] != 0)
			continue;

		visit[i] = 1; // 팀 배정
		q.push(i);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int j = 1; j <= n; j++) {
				if (visit[j] != 0)
					continue; // 팀 배정 이미 되어있음
				if (arr[cur][j] == false) { // 싫어하는 사이
					visit[j] = visit[cur] * -1;
					q.push(j);
				}
			}
		}

		/*cout << "===" << endl;
		 for (int i = 1; i <= n; i++) {
		 cout << visit[i] << " ";
		 }*/
	}
	/*cout << "===" << endl;
	 for (int i = 1; i <= n; i++) {
	 cout << visit[i] << " ";
	 }*/

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1)
			blue.push_back(i);
		else if (visit[i] == -1)
			red.push_back(i);
	}
}

void print(vector<int> v) {
	if (v.size() == n) {
		// 아무도 서로 안 싫어하는 경우 한 팀의 인원이 0이 됨
		int cur = v[v.size() - 1];
		v.pop_back();
		red.push_back(cur);
	}
	cout << v.size() << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	cin >> n;
	memset(arr, true, sizeof(arr));

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		// tmp명 싫어함
		for (int j = 0; j < tmp; j++) {
			int x;

			// i와 x는 서로 싫어함
			cin >> x;
			arr[i][x] = false;
			arr[x][i] = false;
		}
	}

	/*for (int i = 1; i <= n; i++) {
	 for (int j = 1; j <= n; j++) {
	 cout << arr[i][j] << " ";
	 }
	 cout << endl;
	 }
	 */
	solution();

	print(blue);
	print(red);

	return 0;
}
