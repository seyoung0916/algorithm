package dfs;

import java.io.*;
import java.util.*;

/*
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
5
BBBBB
BBGBG
BGGGG
BBRRR
RRRRR
*/
public class boj_10026 {
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static int n;
	static char[][] arr;
	static boolean[][] visited;
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };
	static int count;
	static int count2;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = stoi(br.readLine());
		arr = new char[n][n];
		visited = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			// RGB를 배열에 담음
			for (int j = 0; j < n; j++) {
				arr[i][j] = s.charAt(j);
			}
		}
		count = 0;
		count2 = 0;
		// 정상
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					count++;
					dfs(i, j);
				}
			}
		}
		System.out.println(count);
		// 적록색맹
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 방문 배열 초기화
				visited[i][j] = false;
				if (arr[i][j] == 'G')
					arr[i][j] = 'R';
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					count2++;
					dfs(i, j);
				}
			}
		}
		System.out.println(count2);
	}

	// 방문 시 visited를 true로 변경
	static void dfs(int x, int y) {
		if (visited[x][y])
			return;
		visited[x][y] = true;
		// 오, 왼, 위, 아래
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (arr[nx][ny] == arr[x][y])
					dfs(nx, ny);
			}
		}
	}
}