import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution 
{

    // Complete the miniMaxSum function below.
    static void miniMaxSum(int[] arr) 
    {
        long min=0,max=0;				//declaration and initialization
        Arrays.sort(arr);				//sort the input array
        for(int i=0;i<arr.length-1;++i)
        {
            min+=arr[i];				//minimum sum (sum of least 4 elements)
        }
        for(int i=1;i<arr.length;++i)
        {
            max+=arr[i];				//maximum sum (sum of greatest 4 elements)			
        }
        System.out.print(min + " " + max);		//print output
    }


    private static final Scanner scanner = new Scanner(System.in);

    /*Driver Code : Provided by HackerRank*/
    public static void main(String[] args) 
    {
        int[] arr = new int[5];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < 5; i++) 
	{
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        miniMaxSum(arr);

        scanner.close();
    }
}
