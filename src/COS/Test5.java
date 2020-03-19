package COS;
import java.util.Arrays;

class Test5 {
	
    public int[] solution(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        while(left < right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left += 1;
            right -= 1;
        }
        return arr;
    }

    // The following is main method to output testcase.
    public static void main(String[] args) {
    	Test5 sol = new Test5();
        int[] arr = {1, 4, 2, 3, 5};
        int[] ret = sol.solution(arr);
 
        // Press Run button to receive output.
        System.out.println("Solution: return value of the method is " + Arrays.toString(ret) + " .");
    }
}