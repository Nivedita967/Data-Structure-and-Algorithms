import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution 
{

    // Complete the divisibleSumPairs function below.
    static int divisibleSumPairs(int n, int k, int[] ar) 
    {
        int count=0;					//declaration & initialization
        for(int i=0;i<ar.length-1;i++)
        {
            for(int j=1;j<ar.length;j++)
            {
                if(i<j && (ar[i]+ar[j])%k==0)		//(i,j) pairs where i<j AND (ar[i]+ar[j]) is divisible by k
                {
                    count++;				//increment count
                }
            }
        }
        return count;					//return required no. of pairs
    }

    private static final Scanner scanner = new Scanner(System.in);

    /*Driver Code : Provided by HackerRank*/

    public static void main(String[] args) throws IOException 
    {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[] ar = new int[n];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) 
	{
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = divisibleSumPairs(n, k, ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
