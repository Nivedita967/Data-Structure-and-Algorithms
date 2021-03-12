import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the maxSubarray function below.

    //for maximum Subarray sum 
    //in this we have used Kadane's algorithm to calculate amx subarr sum in O(n) complexity
    static int Subarr(int[]arr){
        int i=0, j, maxsum=Integer.MIN_VALUE, currsum=0;
        for(; i<arr.length; i++){
            int sum= currsum+ arr[i];
            if(sum < arr[i]){
                currsum = arr[i];
                maxsum=  Math.max(maxsum, currsum);
            }
            else{
                currsum= sum;
                maxsum=  Math.max(maxsum, currsum);
            }
        }
        return maxsum;
    }

    //for maximum subsequence sum
    //in this algorithm we first consider only positive numbers sum . but if there are no positive numbers and since we 
    //cant have empty susbequence thus at last taking minimum negative number. 
    static int Subseq(int[]arr){
        int maxsum= Integer.MIN_VALUE;
        int currsum=0;
        boolean flag=false;
        for(int i=0; i<arr.length; i++){
            
            if(arr[i]>0){
                flag=true;
                currsum+=arr[i]; 
                maxsum= Math.max(maxsum, currsum);   
            }
        }
        
        if(!flag){
            for(int i=0; i<arr.length; i++){
                maxsum=  Math.max(maxsum, arr[i]);
            }
        }
        return maxsum;
    }

    // maximum Subarray function to return final ans
    static int[] maxSubarray(int[] arr) {
        int subarrSum= Subarr(arr);
        int subseqSum= Subseq(arr);
        int[]result= new int[2];
        result[0]=subarrSum;
        result[1]=subseqSum;
        return result;
    }

    //driver code as per hackerrank platform
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] arr = new int[n];

            String[] arrItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int arrItem = Integer.parseInt(arrItems[i]);
                arr[i] = arrItem;
            }

            int[] result = maxSubarray(arr);

            for (int i = 0; i < result.length; i++) {
                bufferedWriter.write(String.valueOf(result[i]));

                if (i != result.length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
