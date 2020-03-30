package COS;

// You may use import as below.
import java.util.Arrays;

class Test1 {
    public int[] solution(String[] shirtSize) {
        // Write code here.
        int[] answer = new int[shirtSize.length];
        
        for (int i = 0; i < shirtSize.length; i ++) {
        	if (shirtSize[i] == "XS") {        		
        		answer[0] ++;
        	} else if (shirtSize[i] == "S") {
        		answer[1] ++;
        	} else if (shirtSize[i] == "M") {
        		answer[2] ++;
        	} else if (shirtSize[i] == "L") {
        		answer[3] ++;
        	} else if (shirtSize[i] == "XL") {
        		answer[4] ++;
        	} else {
        		answer[5] ++;
        	}
        }
        return answer;
    }
    
    // The following is main method to output testcase.
    public static void main(String[] args) {
    	Test1 sol = new Test1();
        String[] shirtSize = {"XS", "S", "L", "L", "XL", "S"};
        int[] ret = sol.solution(shirtSize);
 
        // Press Run button to receive output.  
        System.out.println("Solution: return value of the method is " + Arrays.toString(ret) + " .");
    }
}