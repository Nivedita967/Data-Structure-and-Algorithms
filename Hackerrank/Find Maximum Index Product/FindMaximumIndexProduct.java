import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    // Complete the solve function below.
     static long solve(int[] arr) {
        int n=arr.length;

        //storing right greater and left greater for every index of array in 2 different stacks
        long[] right=new long[n];
        long[] left=new long[n];
        Stack<Integer> st1=new Stack<>();
        Stack<Integer> st2=new Stack<>();

        //for left greater 
        left[0]=-1;
        st1.push(0);
        for(int i=1;i<n;i++){
            while(!st1.isEmpty() && arr[i]>=arr[st1.peek()]){
                st1.pop();
            }
            if(st1.isEmpty())left[i]=-1;
            else left[i]=st1.peek();
            st1.push(i);
        }    

        //for right greater
        right[n-1]=-1;
        st2.push(n-1);
            for(int i=n-2;i>=0;i--){
            while(!st2.isEmpty() && arr[i]>=arr[st2.peek()]){
                st2.pop();
            }
            if(st2.isEmpty())right[i]=-1;
            else right[i]=st2.peek();
            st2.push(i);
        }

        //taking maximum product of all left x right indexes product 
        long max=0;
        for(int i=0;i<n;i++){
            max=Math.max(max,(right[i]+1)*(1+left[i]));
        }   
        return max;
    }

    //driver code
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int arrCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[arrCount];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int arrItr = 0; arrItr < arrCount; arrItr++) {
            int arrItem = Integer.parseInt(arrItems[arrItr]);
            arr[arrItr] = arrItem;
        }

        long result = solve(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
