package Leetcode.Find Peek Element;

// Java program to find peek element from a given array
import java.io.*;
import java.util.*;

public class Find_peak_element {
    static int findPeakElement(int[] nums) {
        int c=0;
        //Checking the length
        if(nums.length>1){
        //Checking for the first element
        if(nums[0]>nums[1])
            c=0;
        
        // Checking for all elements except first and last
        for(int i=1;i<nums.length-1;i++){
              if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
                  c=i;
        }
        //Checking for the last element
        if(nums[nums.length-1]>nums[nums.length-2])
            c=nums.length-1;
        }
        else
            c=0;
        // Return the answer    
        return c;
    }

    //Driver's code
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        
        for(int i=0;i<n;i++)
          a[i]=sc.nextInt();

        System.out.println(findPeakElement(a));
    }
}

