
//Java program for goodland electricity
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class goodlandelectricity {

    // Complete the pylons function below.
    static int pylons(int k, int[] arr) {
        int[] dp=new int[arr.length];
        Queue<Integer> queue=new LinkedList<Integer>();
        for(int i=arr.length-1; i>=0; i--) {
            if(arr[i]==1)
                queue.offer(i);
        }
        //using dp approach
        for(int i=arr.length-1; i>=0; i--) {
            dp[i]=-1;
            while(queue.size()>0) {
                int t=queue.peek();
                if(i<=t+k-1 && t-k+1<=i) {
                    dp[i]=t;
                    break;
                }
                queue.poll();
            }
        }

        int start=0;
        int result=0;
        while(start<arr.length) {
            if(dp[start]==-1)
                return -1;
            ++result;
            start=dp[start]+k;
        }

        //return result
        return result;
           
    }

    private static final Scanner scanner = new Scanner(System.in);
    //Driver's code
    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = pylons(k, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
