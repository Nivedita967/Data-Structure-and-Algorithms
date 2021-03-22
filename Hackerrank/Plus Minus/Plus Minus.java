import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);           // Taking user input
        int n = in.nextInt();
        int pos = 0;
        int zero = 0;
        int neg = 0;
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            if (x > 0) {                               // Calculating number of negatives, positives and zero elements
                pos++;
            } else if (x == 0) {
                zero++;
            } else {
                neg++;
            }
        }
        System.out.println(pos / (double) n);           // Printing result in required format 
        System.out.println(neg / (double) n);
        System.out.println(zero / (double) n);
    }
}
