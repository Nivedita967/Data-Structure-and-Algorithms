import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    //implemented using Binary Search method by replacing the max value with its min inside dp array
    //complexity is O(nlogn)
    //folling is normal binary search code
    static int binary(int left, int right, ArrayList<Integer>dp, int key){
            if(left>=right){
                return left;
            }
            if(left<right){
                int mid= (left+right)/2;
                if(dp.get(mid)<key){
                    left= mid+1;
                }
                else{
                    right=mid;
                }
            }
            return binary(left, right, dp, key);
    }
    
    
    // Complete the longestIncreasingSubsequence function below.
    static int longestIncreasingSubsequence(int[] arr) {

        //dp arraylist
        ArrayList<Integer>dp = new ArrayList<Integer>(); 
        int n= arr.length;

        dp.add(arr[0]);

        //replacing the value if it is smaller than already existing one as it gets high chances of making LIS
        //else normally add to dp array 
        for(int i=1; i<n; i++){
            if(arr[i]>dp.get(dp.size()-1)){
                dp.add(arr[i]);
            }
            else{
                int idx = binary(0, dp.size()-1, dp, arr[i]);
                dp.set(idx, arr[i]);
            }
        }
        return dp.size();

    }

    //driver code 
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            int arrItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            arr[i] = arrItem;
        }

        int result = longestIncreasingSubsequence(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
