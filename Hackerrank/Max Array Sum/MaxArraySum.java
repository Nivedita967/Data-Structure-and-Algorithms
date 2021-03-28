import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the maxSubsetSum function below.
    static int maxSubsetSum(int[] arr) {
        // In this we store two values if last element was included or excluded
        int maxsum=Integer.MIN_VALUE;
        int linc = 0;
        int lexc = 0;
        for(int i=0;i<arr.length ;i++){
            // storing current maximum
            int currmax=Integer.MIN_VALUE;
            currmax = Math.max(linc, Math.max(lexc, lexc+arr[i]));
            int temp = lexc;
            // updating last included and excluded values
            lexc = Math.max(linc, lexc);
            linc = temp + arr[i];
            // storing best possible maximum
            maxsum= Math.max(maxsum, currmax);
        }
        // since susbet can be empty , thus for all negative numbers return 0
        if(maxsum < 0) maxsum =0;
        return maxsum;
        
    }

    // Driver Code
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int res = maxSubsetSum(arr);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
