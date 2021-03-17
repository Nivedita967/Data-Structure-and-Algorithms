// Java program to find the maximum subarray
import java.io.*;
import java.util.*;
class Maximum_subarray{
    static long maximumSum(long[] a, long m) {
        long maxSum=0;
  
    TreeSet<Long> prefix = new TreeSet<Long>();
    long currSum=0;
     
    // Travelling through the tree to find subarray
    for(int i=0;i<a.length;i++){
        currSum=(currSum+a[i]%m)%m;
        maxSum=Math.max(maxSum, currSum);
        
        Long pr = prefix.higher(currSum);
        if(pr != null){
            maxSum= Math.max(maxSum, (currSum-pr+m)%m);
        }
        prefix.add(currSum);
    }
    // return the result
    return maxSum;

}
// Driver's code
public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int q = sc.nextInt();
    while(q-->0){
        int n = sc.nextInt();
        long m = sc.nextLong();
        long a[] = new long[n];
        for (int i=0;i<n;i++){
            a[i] = sc.nextLong();
        }
        long res = maximumSum(a, m);
        System.out.println(res);
    }
}
}
