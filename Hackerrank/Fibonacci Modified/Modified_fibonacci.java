import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

 
//* Algorithm =>
//* Can be done in O(n) by using a dynamic programming approach. 
//* Just the case to be handled is for long numbers (number of bits >64).  For this we have used BigInteger in Java. 


public class Solution {

    static BigInteger fibonacciModified(int t1, int t2, int n) {
        BigInteger f1 = BigInteger.valueOf(t1);
        BigInteger f2 = BigInteger.valueOf(t2);
        BigInteger[] dp = new BigInteger[n];
        dp[0] = f1;
        dp[1] = f2;
        for (int i = 2; i < n; i++){
            dp[i] = dp[i - 1].multiply(dp[i - 1]).add(dp[i - 2]);
        }
        return dp[n-1];
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] t1T2n = scanner.nextLine().split(" ");
        int t1 = Integer.parseInt(t1T2n[0]);
        int t2 = Integer.parseInt(t1T2n[1]);
        int n = Integer.parseInt(t1T2n[2]);
        BigInteger result = fibonacciModified(t1, t2, n);
        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
