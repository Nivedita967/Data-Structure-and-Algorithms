/*
A java program to reverse a number.
If a number is given this program returns the reverse of that number.
*/

public class Solution {

  public int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
      int temp = reversed * 10 + x % 10;
      x = x / 10;
      if (temp / 10 != reversed) {
        return 0;
      }
      reversed = temp;
    }

    return reversed;
  }
}

/*
Sample Case : 
Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321
*/
