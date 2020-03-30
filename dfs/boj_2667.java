package dfs;

import java.io.*;
import java.util.*;

/*
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
*/
public class boj_2667 {
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static int n;
	static int[][] arr;
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };
	static int count;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		n = stoi(br.readLine());
		arr = new int[n][n];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			// 숫자로 변환
			for (int j = 0; j < n; j++)
				arr[i][j] = s.charAt(j) - '0';
		}
		/**
		 * total은 총 단지수 count는 각 단지의 개수 오름차순으로 출력하기 위해 PriorityQueue에 저장함
		 */
		int total = 0;
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) {
					count = 0;
					// 단지 하나 추가
					total++;
					dfs(i, j);
					System.out.println("count : " + count);
					pq.add(count);
				}
			}
		}
		// 많은 양의 출력에서 효율적
		bw.write(total + "\n");
		while (!pq.isEmpty())
			bw.write(pq.poll() + "\n");
		// 남아있는 데이터 모두 출력
		bw.flush();
	}

	// visited 대신 단지를 0으로 바꿔가면서 체크
	static void dfs(int x, int y) {
		arr[x][y] = 0;
		count++;
		// 오, 왼, 위, 아래
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (arr[nx][ny] == 1)
					dfs(nx, ny);
			}
		}
	}
}