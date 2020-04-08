#include <bits/stdc++.h>

using namespace std;

#define MAX 20

int N;
int arr[MAX][MAX];
int ans = 987654321;

int countAbility(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i];

		for (int j = i + 1; j < v.size(); j++) {
			int y = v[j];

			sum += arr[x][y] + arr[y][x];
		}
	}
	return sum;
}

void solution() {
	// permutation을 위한 vector
	vector<int> check;
	for (int i = 0; i < N; i++) {
		if (i < N / 2)
			check.push_back(0);
		else
			check.push_back(1);
	}

	do {
		vector<int> va, vb;
		int a, b; // A, B팀 능력

		for (int i = 0; i < check.size(); i++) {
			if (check[i] == 0) // a팀
				va.push_back(i);
			else
				// b팀
				vb.push_back(i);
		}

		a = countAbility(va);
		b = countAbility(vb);

		cout << "a ability " << a << " b ability " << b << endl;

		ans = (ans > abs(a - b)) ? abs(a - b) : ans;

	} while (next_permutation(check.begin(), check.end()));
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	solution();
	cout << ans;

	return 0;
}
