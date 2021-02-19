/*
A java program to implement Powe of Three
Given an integer n, return true if it is a power of three. Otherwise, return false.
*/

class Solution {
    public boolean isPowerOfThree(int n) {
        if(n < 1){
            return false;
        }
        
        while(n % 3 == 0){
            n = n / 3;
        } 
        
        return n == 1;
    }
}

/*
Sample Input/Output:
Example 1:
Input: n = 27
Output: true

Example 2:
Input: n = 0
Output: false
*/
