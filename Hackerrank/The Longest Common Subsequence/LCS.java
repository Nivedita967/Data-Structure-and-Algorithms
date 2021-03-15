import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the longestCommonSubsequence function below.
    static int[] longestCommonSubsequence(int[] a, int[] b) {

        //dp array to store which numbers become ans of my subsequence
        int[][] dp= new int[a.length+1][b.length+1];
        for(int i=1; i<=a.length; i++){
            for(int j=1; j<=b.length; j++){

                //Case 1: if current index numbers are equal
                if(a[i-1]== b[j-1]){
                    dp[i][j]= dp[i-1][j-1]+1;
                }

                //Case 2: if current index numbers are not equal
                else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int i=a.length;
        int j=b.length;
        // arraylist to store final result
        ArrayList<Integer> v= new ArrayList<Integer>();

        //traversing back in dp array
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                v.add(a[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
                else 
                    j--;
            }
        }

        ///revering arraylist to get correct order
        Collections.reverse(v);
        int[] result = new int[v.size()];

        //converting arraylist to array in order to make it compatible for return type
        for(int x=0; x<v.size(); x++){
            result[x]= v.get(x);
        }
        return result;
    }

    //driver coder
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        int[] a = new int[n];

        String[] aItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int aItem = Integer.parseInt(aItems[i]);
            a[i] = aItem;
        }

        int[] b = new int[m];

        String[] bItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            int bItem = Integer.parseInt(bItems[i]);
            b[i] = bItem;
        }

        int[] result = longestCommonSubsequence(a, b);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
