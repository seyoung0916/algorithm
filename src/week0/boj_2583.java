package week0;

import java.util.*;
import java.io.*;

public class boj_2583 {
	static int w, h, n;
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };
	static char[][] map;
	static int count, area;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		String[] s = br.readLine().split(" ");
		w = Integer.parseInt(s[1]); // 가로길이
		h = Integer.parseInt(s[0]); // 세로길이
		n = Integer.parseInt(s[2]);
		map = new char[h][w];
		// N으로 초기화
		for (int m = 0; m < h; m++) {
			for (int n = 0; n < w; n++) {
				map[m][n] = 'N';
			}
		}
		for (int i = 0; i < n; i++) {
			s = br.readLine().split(" ");
			int x1 = Integer.parseInt(s[0]);
			int y1 = Integer.parseInt(s[1]);
			int x2 = Integer.parseInt(s[2]);
			int y2 = Integer.parseInt(s[3]);
			// 입력한대로 사각형 그리기
			for (int m = h - y2; m < h - y1; m++) {
				for (int n = x1; n < x2; n++) {
					map[m][n] = 'Y';
				}
			}
		}
		/*
		 * // 사각형 그린 후 System.out.println("---사각형----"); for (int m = 0; m < h; m++) {
		 * for (int n = 0; n < w; n++) { System.out.print(map[m][n]); }
		 * System.out.println(""); } System.out.println("----------");
		 */
		for (int m = 0; m < h; m++) {
			for (int n = 0; n < w; n++) {
				// System.out.println("x : " + m + " y : " + n);
				if (map[m][n] == 'N') {
					count++; // 구역 + 1
					// System.out.println("count : " + count);
					area = 0; // 면적 초기화
					dfs(m, n);
					pq.add(area);
					/*
					 * 한 번 dfs 돈 후 사각형 System.out.println("---사각형2----"); for (int j = 0; j < h;
					 * j++) { for (int k = 0; k < w; k++) { System.out.print(map[j][k]); }
					 * System.out.println(""); } System.out.println("----------");
					 */
				}
			}
		}
		bw.write(count + "\n");
		while (!pq.isEmpty()) {
			bw.write(pq.poll() + "\n");
		}
		bw.flush();
	}

	static void dfs(int x, int y) {
		map[x][y] = 'Y'; // 방문 체크
		area++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (map[nx][ny] == 'N') {
					dfs(nx, ny);
				}
			}
		}
	}
}