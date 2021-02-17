/*
A java program to find out Power of Two or not.
Given an integer n, return true if it is a power of two. Otherwise, return false.
*/

class Solution {
    public boolean isPowerOfTwo(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>>= 1;
        }
        return count == 1;       
    }
}

/*
Sample Case:
Example 1:
Input: n = 1
Output: true

Example 3:
Input: n = 3
Output: false
*/
