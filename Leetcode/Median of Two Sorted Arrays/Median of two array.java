
/*Java program to find median of two sorted arrays*/
import java.io.*;
import java.util.*;
class Median {
    static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        //Find the mid 
        int mid = ((nums1.length + nums2.length) / 2) + 1;
        int[] result = new int[mid];
        int i1 = 0, i2 = 0, ir=0;
        while (ir < mid && i1 < nums1.length && i2 < nums2.length){
            int val1 = nums1[i1];
            int val2 = nums2[i2];
            if(val1 < val2){
                result[ir++] = val1;
                i1++;
            }else{
                result[ir++] = val2;
                i2++;
            }
        }

        int il = i1 < nums1.length ? i1 : i2;
        int[] numl = i1 < nums1.length ? nums1 : nums2;
        for (; ir < result.length; il++){
            result[ir++] = numl[il];
        }
        // If the length of array is even
        if ((nums1.length + nums2.length) % 2 == 0) {
            return (double) ((double) result[mid-2] + (double) result[mid-1]) / (double) 2;
        }
        // If the length of array is odd
         else {
            return (double) result[mid-1];
        }
    }
    //Driver's code
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int a1[] = new int[n];
        int a2[] = new int[m];
        for(int i=0;i<n;i++)
          a1[i]=sc.nextInt();
        for(int i=0;i<m;i++)
          a2[i]=sc.nextInt();

    double ans = findMedianSortedArrays(a1,a2);
    System.out.println(ans);
    }
}

