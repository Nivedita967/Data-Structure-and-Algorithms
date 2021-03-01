/*

For an  n x n matrix, if i and j denote the row no. and column no. respectively,for elements on
Same row: i-value remains same, j-value varies from 0 to (n-1)
Same col: i-value varies from 0 to (n-1), j-value remains same
Non-principal diagonal (npd)(top-right to bottom-left): i+j=(n-1)
Right of Non-principal diagonal: i+j>(n-1)

*/
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the staircase function below.
    static void staircase(int n) {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i+j>=n-1)					//positions on npd and right of npd
                    System.out.print("#");
                else						//position left of npd
                    System.out.print(" ");
            }
            System.out.print("\n");				//next line
        }

    }

    private static final Scanner scanner = new Scanner(System.in);

    /*Driver Code : Provided by HackerRank*/
    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        staircase(n);

        scanner.close();
    }
}
