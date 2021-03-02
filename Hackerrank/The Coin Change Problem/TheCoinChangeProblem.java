import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;
public class Solution {

    static long getWays(int amount, int[] coins){
        
        //solved using dynamic programming approach
        long[] dp = new long[amount + 1];
        
        //ways to pay amount 0 is only 1 i.e. not to give any coin
        dp[0] = 1;
        
        //outer loop works on coin array
        for(int coin : coins){

            //inner loop works on dp array
            for(int i = 1; i < dp.length; i++){
                if(i >= coin){

                    //adding the number ways to pay i-coin 
                    dp[i] += dp[i - coin];
                }
            }
           }

        //returning no of ways to pay amount.   
        return dp[amount];
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] c = new int[m];
        for(int c_i=0; c_i < m; c_i++){
            c[c_i] = in.nextInt();
        }
        // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
        long ways = getWays(n, c);
        System.out.println(ways);
    }
}