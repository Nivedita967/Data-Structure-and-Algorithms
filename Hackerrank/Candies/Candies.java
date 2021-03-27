
//Java program for hackerrank problem 'candies'
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Candies {

    // Complete the candies function below.
    static long candies(int n, int[] arr) {

     int[] candies = new int[n];
    //initializing first element of candies array to zero
    candies[0] = 1;
    for(int i=1; i<n; i++)
    //checking if the previous element is smaller than the ith element
        if(arr[i-1] < arr[i])
            candies[i] = candies[i-1] + 1;
        else
            candies[i] = 1;


    long sumCandies = candies[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i] > arr[i+1])
            candies[i] = Math.max(candies[i+1] + 1, candies[i]);
            //calculating sum of candies
        sumCandies += candies[i];
    }

    return sumCandies;
    }

    private static final Scanner sc = new Scanner(System.in);
    //Driver's code
    public static void main(String[] args) throws IOException {
        
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
          arr[i] = sc.nextInt();
          
        System.out.println(candies(n,arr));
    }
}

