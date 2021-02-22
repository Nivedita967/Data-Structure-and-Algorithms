import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the unboundedKnapsack function below.
    static int unboundedKnapsack(int k, int[] arr) {

        //creating a dp array with default value 0
        int[] dp= new int[k+1];
        Arrays.fill(dp, 0);

        //for loop runnning . the outer one on items array and inner one on dp array
        for(int i=0;i <arr.length; i++){
            for(int j=1; j<=k; j++){
                if(j-arr[i]>=0){
                    //taking two consideration if the item is accepted and if the item is not accepted and taking the maximum of the two.
                    dp[j] = Math.max(dp[j-arr[i]] + arr[i], dp[j]);
                }
            }
        }
        return dp[k];
    }

    //driver function 
    private static final Scanner scanner = new Scanner(System.in);

     public static void main(String[] args) {
       
        
        BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
        int nums[];
        try {
            int t = Integer.parseInt(b.readLine());
            
            while(t-- > 0) {
                String nk[] = b.readLine().split(" ");
                int n = Integer.parseInt(nk[0]);
                int k = Integer.parseInt(nk[1]);
                
                nums = new int[n];
                String numbers[] = b.readLine().split(" ");
                for (int i = 0; i < n; i++) {
                    nums[i] = Integer.parseInt(numbers[i]);
                }
                
                System.out.println(unboundedKnapsack(k, nums));
            }
        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                b.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } 
    }
}
