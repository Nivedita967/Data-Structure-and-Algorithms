// Problem Statement
// Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

class Solution {
    public int minAddToMakeValid(String S) {
        // Initialize an empty stack
        Stack<Character> stack = new Stack();
        for(int i = 0 ; i < S.length() ;i++){
            // if the character is '(' then push it to the stack
            if(S.charAt(i) == '(' ){
                stack.push(S.charAt(i));
            }
            // if the character is `)` then pop stack i.e. pop `(`
            else if(S.charAt(i) == ')' && (!stack.isEmpty() && stack.peek() == '(')){
                stack.pop();
            }
            else{
                stack.push(S.charAt(i));
            }
        }
        // All left out elements of stack would give the count of chars to make paranthesis valid.
        return stack.size();
    }
}