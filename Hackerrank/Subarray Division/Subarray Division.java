/*
Two children, Lily and Ron, want to share a chocolate bar. Each of the squares has an integer on it.
Lily decides to share a contiguous segment of the bar selected such that:
The length of the segment matches Ron's birth month, and,
The sum of the integers on the squares is equal to his birth day.
Determine how many ways she can divide the chocolate.


*/

import java.util.*;

public class Solution {
    
    public static int getNumberOfWays(int n, int d, int m, int[] sum) {
        // Modify array to make each 'i' contain the running sum of prior elements
        for (int i = 1; i < n; i++) {
            sum[i] += sum[i - 1];
        }
        
        // Set number of ways counter
        // If there are >= 'm' squares AND the first possible piece has sum = 'd', 1
        // Else, 0
        int numberOfWays = (m <= n && sum[m - 1] == d) ? 1 : 0;
        
        // Check the sums for pieces ending at index 'm' through 'n - 1'
        for (int i = m; i < n; i++) {
            // If the sum of the piece is equal to 'd'
            if (sum[i] - sum[i - m] == d) {
                // Increment ways counter
                numberOfWays++;
            }
        }
        
        return numberOfWays;
    }
}