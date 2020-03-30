package week0;

import java.io.*;
import java.util.*;

/*4
1 1 0 0
0 0 1 1
0 0 0 0
1 1 1 1*/

/*10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0*/

public class boj_2146 {

	static int N;
	static int[][] map; // 입력받은 배열
	static int[][] sum; // 섬 배열
	static int[][] len; // 길이 배열
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		sum = new int[N][N];
		len = new int[N][N];

		// 입력
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// 섬 네이밍
		// 섬을 표시할 변수
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 섬이 있는 위치이고 , 섬배열에 값이 없으면
				if (map[i][j] == 1 && sum[i][j] == 0) {
					Queue<Node> q = new LinkedList<Node>();
					sum[i][j] = ++cnt;
					q.add(new Node(i, j));

					while (!q.isEmpty()) {
						Node cur = q.poll();
						int x = cur.x;
						int y = cur.y;

						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
								if (map[nx][ny] == 1 && sum[nx][ny] == 0) {
									q.add(new Node(nx, ny));
									sum[nx][ny] = cnt;
								}
							}
						}

					}
				}
			}
		}

		Queue<Node> q = new LinkedList<>();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 모두 -1로 넣고
				len[i][j] = -1;
				if (map[i][j] == 1) { // 섬이 있는 위치를 0으로 표시
					q.add(new Node(i, j)); // 큐에는 섬 위치를 차례로 넣음
					len[i][j] = 0;
				}
			}
		}

		while (!q.isEmpty()) {
			Node cur = q.poll();

			int x = cur.x;
			int y = cur.y;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (len[nx][ny] == -1) { // 섬이 아닌 곳
						len[nx][ny] = len[x][y] + 1; // 기존 + 1
						sum[nx][ny] = sum[x][y];
						q.add(new Node(nx, ny));
					}
				}
			}
			// printMap();
		}
		// printMap();

		int ans = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (sum[i][j] != sum[nx][ny]) { // 인접한 섬이 다르면
							if (ans == -1 || ans > len[i][j] + len[nx][ny]) {
								ans = len[i][j] + len[nx][ny];
							}
						}
					}
				}
			}
		}
		System.out.println(ans);
	}

	static void printMap() {
		System.out.println("print =====");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.print(sum[i][j] + "   ");
			}
			System.out.println("");
		}
		System.out.println("=====");
	}

	static class Node {
		int x;
		int y;

		public Node(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
	}
}
