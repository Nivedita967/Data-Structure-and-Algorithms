// Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" then
//  f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.
// You are given an array of strings words and another array of query strings queries. For each query queries[i], count the number of words in words such that
//  f(queries[i]) < f(W) for each W in words.
// Return an integer array answer, where each answer[i] is the answer to the ith query.
// Example 1:

// Input: queries = ["cbd"], words = ["zaaaz"]
// Output: [1]
// Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

// Example 2:

// Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
// Output: [1,2]
// Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").

// import java.io.*; 
import java.util.*; 
class Solution {
    private int cal(String s){
        char smallest = 'z'; // Since z is alphabetically largest char.
        char[] arr = s.toCharArray(); // convert string s to a character array
        // Traverse each character of arr & find smallest character of string
        for(char c : arr){
            if(c < smallest){
                smallest = c;
            }
        }
        // Traverse each element of arr & find the frequency of smallest char
        int count = 0;
        for(char d : arr){
            if(d == smallest){
                count++;
            }
        }
        // return the frequency
        return count;
    }
    
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        List<Integer> ql = new ArrayList<Integer>(); // Array list of queries
        List<Integer> wl = new ArrayList<Integer>(); // Arraylist of words
        
        // Calculate the frequency of smallest character for each elements in queries & add to ql
        for(String s : queries){
            int c = cal(s);
            
            ql.add(c);
        }
        // Calculate the frequency of smallest character for each elements in words & add to wl
        for(String t : words){
            int c = cal(t);
            
            wl.add(c);
        }
        int[] ans = new int[queries.length];
        int x =0;
        // Comparing the Strings by frequency of smallest character
        for(int i = 0;i < queries.length;i++){
            int count = 0;
            for(int j = 0; j < words.length ; j++){
                if(ql.get(i) < wl.get(j)){
                    count++;
                }
            }
            ans[x] = count;
            x++;
        }
        
        return ans;
    }
}
    

