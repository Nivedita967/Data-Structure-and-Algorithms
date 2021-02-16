/*
Java Program to check whether a number is Palindrome or not
An integer is a palindrome if the reverse of that number is equal to the original number.
Example of Palindromes are 11,44,101,121.
*/

public class Solution {
  public boolean isPalindrome(int x) {
    if (x < 0 || x != 0 && x % 10 == 0) {
      return false;
    }

    // reverse process
    int reversed = 0;
    int original = x;
    while (x != 0) {
      reversed = reversed * 10 + x % 10;
      x = x / 10;
    }

    return reversed == original;
  }
}

/*

Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false

*/
