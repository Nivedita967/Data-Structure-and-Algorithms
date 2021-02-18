/*
A java program to find Length of Last Word
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
*/

class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length(), result = 0;
        while(n > 0){
            if(s.charAt(--n) != ' ') result++;
            else if(result > 0) return result;
        }
        return result;
    }
}

/*
Sample Case:
Example 1:
Input: s = "Hello World"
Output: 5

Example 2:
Input: s = " "
Output: 0
*/
