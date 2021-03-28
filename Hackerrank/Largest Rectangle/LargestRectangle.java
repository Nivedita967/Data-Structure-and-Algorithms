import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the largestRectangle function below.
    static long largestRectangle(int[] h) {
        long maxans=0;
        Stack<Integer>stk=new Stack<>(); 
        // initially keep -1 in stack
        stk.push(-1);
        int i;
        for(i=0;i<h.length;i++){

            // pop until either stk is not empty or element at top of stack is not greater than current element
            if( ( stk.peek()!=-1 && h[stk.peek()]<=h[i]) || stk.size()==1){
                stk.push(i);
            }

            //calculate current area (idth is assumed to be 1 by default for each bar)
            else{
                while(stk.size()!=0 && stk.peek()!=-1 && h[stk.peek()]>=h[i]){
                    int idx=stk.pop();
                    int height=h[idx];
                    int width=i-stk.peek()-1;
                    maxans=Math.max((long)height*width, maxans);
                }
                stk.push(i);
            }
            
        }

    //emptying the stack at the last
        while(stk.size()!=1 ){
            int idx=stk.pop();
            int height=h[idx];
            int width=i-stk.peek()-1;
            maxans=Math.max((long)height*width, maxans);
        }
       return maxans;
    }

    //driver function
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] h = new int[n];

        String[] hItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int hItem = Integer.parseInt(hItems[i]);
            h[i] = hItem;
        }

        long result = largestRectangle(h);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
