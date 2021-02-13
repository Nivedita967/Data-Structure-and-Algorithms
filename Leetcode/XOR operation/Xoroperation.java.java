import java.io.*;
class Xoroperation {
    public int xorOperation(int n, int start) {
        // Function to find the XOR of 
    // all elements in the array 
        int[] ar = new int[n];
     // Iterating through every element in 
        // the array
        for(int i = 0; i < n; i++) {
            ar[i] = start + 2*i;
        }

        int result = start;
        for(int i = 0; i < n-1; i++) {
            result = result ^ ar[i+1];
        }
    //Return the XOR 
        return result;  
    }
}