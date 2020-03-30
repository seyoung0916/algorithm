package search;

public class SearchAlgorithm {

	int binarySearch(int arr[], int l, int r, int x) { // 매개변수 : 배열이름, 배열 시작 인덱스, 배열 끝 인덱스, 찾으려는 값

		System.out.println("l값 : " + l + "   r값 : " + r);

		if (r >= l) {

			int mid = l + (r - l) / 2; // 중간 값 선택

			if (arr[mid] == x) // 비교하여 찾는 값이라면

				return mid; // 해당 인덱스 반환

			if (arr[mid] > x) // 찾으려는 값보다 크다면

				return binarySearch(arr, l, mid - 1, x); // 좌측 배열 탐색

			return binarySearch(arr, mid + 1, r, x); // 우측 배열 탐색
		}

		return -1; // 찾으려는 값이 없다면 -1 반환
	}

	public static void main(String[] args) {

		SearchAlgorithm sa = new SearchAlgorithm();

		int[] arr = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 }; // 24개

		System.out.println(sa.binarySearch(arr, 0, 23, 18));
		;
	}
}