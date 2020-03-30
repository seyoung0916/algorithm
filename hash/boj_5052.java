package hash;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_5052 {
	public static boolean Solution(String[] arr) {
		// 뒤 원소가 앞 원소를 포함하고 있으면 false 반환
		for (int j = 0; j < arr.length - 1; j++) {
			if (arr[j + 1].startsWith(arr[j])) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 테스트케이스 입력
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			// 입력받을 전화번호 개수만큼 배열 크기 설정
			String[] arr = new String[Integer.parseInt(br.readLine())];
			for (int j = 0; j < arr.length; j++) {
				arr[j] = br.readLine();
			}
			// 정렬
			Arrays.sort(arr);
			String flag = (Solution(arr)) ? "YES" : "NO";
			System.out.println(flag);
		}
	}
}