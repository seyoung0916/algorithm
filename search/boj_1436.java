package search;

import java.io.BufferedReader;
import java.io.InputStreamReader;

// 666을 포함하는 N번째 숫자 찾기	
public class boj_1436 {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int num = 0;

		while (N > 0) {
			num++;

			if (Integer.toString(num).contains("666")) {
				N--;
			}
		}
		System.out.println(num);
	}
}