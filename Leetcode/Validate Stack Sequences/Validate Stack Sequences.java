// Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of 
// push and pop operations on an initially empty stack.

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack(); // Create an empty stack
        int i = 0;
        
        for(int num : pushed){
            stack.push(num);
            // Pop until the top element of stack = ith element of popped array
            while(!stack.empty() && stack.peek() == popped[i]){
                stack.pop();
                i++;
            }
        }
        // condition to validate stack sequence
       return i == popped.length;
    }
}