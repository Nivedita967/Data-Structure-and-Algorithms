/*
A java Program to find it is a valid anagram or not 
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Given two strings s and t , write a function to determine if t is an anagram of s.
*/


class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;
        
        int[] char_counts = new int[26];
        for(int i=0; i<s.length(); i++) {
            char_counts[s.charAt(i)- 'a']++;
            char_counts[t.charAt(i)- 'a']--;
        }
        
        for (int count : char_counts) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
}

/*
Sample Case
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/
