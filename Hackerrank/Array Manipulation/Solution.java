import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the arrayManipulation function below.
    static long arrayManipulation(int n, int[][] queries) {
        long[] arr=new long[n];

        //filling initial value as 0 to the array
        Arrays.fill(arr, 0);

        //running loop on queries
        for(int i=0;i<queries.length;i++){

            //adding and subtracting the given value from certain indexes
            int left =queries[i][0]-1;
            int right = queries[i][1];
            int val= queries[i][2];
            arr[left]+=val;
            if(right < n){
                arr[right]-=val;
            }
        }

        //taking prefix sum
        long maximum = Long.MIN_VALUE;
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
            maximum= Math.max(maximum, arr[i]);
        }

        //returning maximum value in arr.
        return maximum;
    }

    //driver function
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        int[][] queries = new int[m][3];

        for (int i = 0; i < m; i++) {
            String[] queriesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int queriesItem = Integer.parseInt(queriesRowItems[j]);
                queries[i][j] = queriesItem;
            }
        }

        long result = arrayManipulation(n, queries);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
