#include <bits/stdc++.h>

using namespace std;

#define MAX 8

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int T, N, K, ans;
int arr[MAX][MAX];
bool visit[MAX][MAX];
bool kFlag, retFlag;
vector<pair<int, int>> v;

void dfs(int i, int j, int cnt) {
	retFlag = true; // 네 방향 중 갈  곳이 없다고 가정, ret 해야함
	//cout << "dfs i " << i << " j " << j << " cnt " << cnt << endl;
	for (int d = 0; d < 4; d++) {
		int nx = i + dx[d];
		int ny = j + dy[d];
		//cout << "nx " << nx << " ny " << ny << endl;

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (!visit[nx][ny]) { // 다음 위치 방문 가능
				if (arr[i][j] > arr[nx][ny]) { // 정상 등산로
					//cout << "정상 " << endl;
					retFlag = false;
					visit[nx][ny] = true;
					dfs(nx, ny, cnt + 1);
					visit[nx][ny] = false;
				} else { // 다음등산로가 더 높을 때
					// 깎기 가능 상태
					if (kFlag == true) {
						int tmp = arr[nx][ny];
						for (int dep = 1; dep <= K; dep++) {
							int next = arr[nx][ny] - dep; // K만큼 깎음
							if (next < 0)
								next = 0;

							//cout << "next 값 " << next << endl;
							if (next < arr[i][j]) {
								retFlag = false;
								// 이전 산봉우리보다 작으면 등산로 만들기 가능
								visit[nx][ny] = true;
								kFlag = false;
								arr[nx][ny] = next; // 깎은 상태
								//cout << "깎음" << endl;
								dfs(nx, ny, cnt + 1);
								arr[nx][ny] = tmp; // 원래 높이로
								visit[nx][ny] = false;
								kFlag = true;
							}
						}

					}
				}
			}
		}
		//cout << "ret Flag " << retFlag << endl;
	}
	if (retFlag == true) {
		ans = max(ans, cnt);
		//cout << ans << endl;
		return;
	}
}

int main() {
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		int m = 0;
		ans = 0;
		memset(arr, 0, sizeof arr);
		memset(visit, 0, sizeof visit);

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				// 지도의 최대 산봉우리 값
				m = (arr[i][j] > m) ? arr[i][j] : m;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == m) {
					kFlag = true; // K만큼 깎기 가능한 상태
					visit[i][j] = true;
					//cout << "-----" << i << " " << j << "-----" << endl;
					dfs(i, j, 1);
					visit[i][j] = false;
				}
			}
		}

		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}
