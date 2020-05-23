package week0;

import java.io.*;
import java.util.*;

public class boj_3055 {
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };
	static char[][] map;
	static int[][] count;
	static int x, y;

	static void bfs() {
		Queue<point> q = new LinkedList<>();
		// 물 위치 저장
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (map[i][j] == '*')
					q.add(new point(i, j, '*'));
			}
		}
		// 고슴도치 저장
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (map[i][j] == 'S')
					q.add(new point(i, j, 'S'));
			}
		}
		while (!q.isEmpty()) {
			/*
			 * for (int i = 0; i < x; i++) { for (int j = 0; j < y; j++) {
			 * System.out.print(map[i][j]); } System.out.println(""); }
			 * System.out.println("----");
			 */
			point p = q.poll();
			for (int i = 0; i < 4; i++) {
				// 이동할 위치
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				// System.out.println("nx : " + nx + " ny : " + ny);
				if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
					// 물 타일
					if (p.ch == '*') {
						if (map[nx][ny] != 'D' && map[nx][ny] != 'X' && map[nx][ny] != '*') {
							map[nx][ny] = '*';
							q.add(new point(nx, ny, '*'));
						}
					}
					// 고슴도치 타일 + 다음 턴의 물 타일을 신경 안쓰고 모든 경우의 수 따짐
					if (p.ch == 'S') {
						if (map[nx][ny] == '.' || map[nx][ny] == 'D') {
							// 현 위치까지 이동한 시간 + 1
							count[nx][ny] = count[p.x][p.y] + 1;
							if (map[nx][ny] == 'D')
								return;
							// 고슴도치가 이동 후
							map[nx][ny] = 'S';
							// 고슴도치가 이동한 자리 .으로 바꿈
							// map[p.x][p.y] = '.'; >> 주석처리 하니 메모리 초과해결 됐는데 이유 모르겠음
							q.add(new point(nx, ny, 'S'));
						}
					}
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = br.readLine().split(" ");
		x = Integer.parseInt(arr[0]);
		y = Integer.parseInt(arr[1]);
		map = new char[x][y];
		count = new int[x][y];
		for (int i = 0; i < x; i++) {
			String s = br.readLine();
			for (int j = 0; j < y; j++) {
				map[i][j] = s.charAt(j);
			}
		}
		bfs();
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (map[i][j] == 'D') {
					if (count[i][j] == 0) {
						System.out.println("KAKTUS");
					} else {
						System.out.println(count[i][j]);
					}
				}
			}
		}
	}

	static class point {
		int x;
		int y;
		int ch;

		public point(int x, int y, int ch) {
			super();
			this.x = x;
			this.y = y;
			this.ch = ch;
		}
	}
}