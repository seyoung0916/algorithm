package search;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_10815 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine()); // 자연수 N
		int[] arr = new int[n]; // 숫자로 바꿔 담을 배열
		String[] beforeArray = br.readLine().split(" "); // 스트링 배열로 받아지는 특징 때문에 인트배열 담기 전에 생성

		/* 스트링 배열로 들어온 문자를 정수 배열로 바꿔줌 */
		for (int i = 0; i < beforeArray.length; i++) {
			arr[i] = Integer.parseInt(beforeArray[i]);
		}

		/* 이진탐색을 위한 오름차순으로 정렬 */
		Arrays.sort(arr);

		int m = Integer.parseInt(br.readLine()); // M개의 수
		String[] beforeComArray = br.readLine().split(" ");
		int[] compareArr = new int[m]; // 숫자로 바꿔 담을 배열

		/* 스트링 배열로 들어온 문자를 인트 배열로 바꿔줌 */
		for (int j = 0; j < beforeComArray.length; j++) {
			compareArr[j] = Integer.parseInt(beforeComArray[j]); // 주어질 수에 대한 배열
		}

		for (int i = 0; i < compareArr.length; i++) { // 지금부터 주어진 수가 aArray 배열에 담긴 수와 일치하는지 반복문을 통해 찾을 것이다.
			int flag = 0;

			/* 인덱스의 시작과 끝 */
			int r = arr.length - 1;
			int l = 0;
			int middle;

			while (r >= l) {
				middle = (l + r) / 2;

				if (compareArr[i] == arr[middle]) {
					flag = 1;
					break;
				}
				if (compareArr[i] > arr[middle]) {
					l = middle + 1;
				} else if (compareArr[i] < arr[middle]) {
					r = middle - 1;
				}

			}
			System.out.print(flag + " ");
		}
	}
}