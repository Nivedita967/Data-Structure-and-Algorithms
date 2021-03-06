
// Java program to find the length of longest valid parentheses
import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
    public static int longestValidParentheses(String s) {
        int n = s.length();
 
       
        Stack<Integer> st = new Stack<>();

        //Initializing the stack to -1
        st.push(-1);
 
        
        int res = 0;
 
        //for loop to extract each character and check
        for (int i = 0; i < n; i++) 
        {
           
            if (s.charAt(i) == '(')
            //pusing into stack
                st.push(i);
 
          
            else
            {
                //poping out from stack
                    st.pop();
 
               //if stack is not empty then max is stored in res
                if (!st.empty())
                    res = Math.max(res, 
                                   i - st.peek());
 
               
                else
                    st.push(i);
            }
        }
        // return the result
        return res;
}

public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter parentheses");
    String s = sc.nextLine();
    System.out.println(longestValidParentheses(s));
}
}