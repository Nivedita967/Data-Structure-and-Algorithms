/*HackerRank : Algorithms>Implementation>Jumping on the Clouds*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the jumpingOnClouds function below.
    static int jumpingOnClouds(int[] c) {
        int jumps=0;		//declaration and initialization
        int i=0;		//declaration and initialization
        while(true)		//infinite loop
        {
            if(i+2<c.length && c[i+2]==0)   //checking if 2 steps can be taken by checking cloud type at 2nd step
            {
                i+=2;
            }
            else if(i+1<c.length)	//checking if 1 step can be taken by checking if we have any more clouds left
            {
                i++;
            }
            else
            {
                break;		//to exit from the infinite while loop if the above conditions are not met
            }
            jumps++;
        }
        return jumps;		//returns required minimum no. of jumps

    }

    private static final Scanner scanner = new Scanner(System.in);	//to take input

    /*Driver Code : Provided by HackerRank*/
    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");     //skips an input which matches the pattern

        int[] c = new int[n];

        String[] cItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int cItem = Integer.parseInt(cItems[i]);
            c[i] = cItem;
        }

        int result = jumpingOnClouds(c);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
