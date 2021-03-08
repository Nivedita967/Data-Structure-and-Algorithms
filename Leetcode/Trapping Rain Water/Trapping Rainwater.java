
// Java program to compute how much water can be trapped between the blocks during the rainy season. 
import java.io.*;
import java.util.*;

class Trap {
    static int trap(int arr[]) { 
        
        // Your code here
        int n = arr.length;
        int left[] = new int[n];
 
        
        int right[] = new int[n];
 
        // Initialize result
        int water = 0;
 
        // Fill left array
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = Math.max(left[i - 1], arr[i]);
 
        // Fill right array
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = Math.max(right[i + 1], arr[i]);
 
        //min value stored in water
        for (int i = 0; i < n; i++)
            water += Math.min(left[i], right[i]) - arr[i];
 
        //return the result
        return water;
        
    } 

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
         a[i]=sc.nextInt();

        System.out.println(trap(a));
    }
}
