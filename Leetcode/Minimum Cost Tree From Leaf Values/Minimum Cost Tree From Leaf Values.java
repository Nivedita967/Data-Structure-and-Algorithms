class Solution {
    public int mctFromLeafValues(int[] arr) {
        //Defining the answer
        int ans = 0;
        //Creating a stack that initially contains Integer max value
        Stack<Integer> stack = new Stack<>();
        stack.push(Integer.MAX_VALUE);
        //Looping through the array
        for (int a : arr) {
            //While the top of the stack is less than or equal to current array index value, then we pop it and after calculating minimum of current top of stack and current array value, we multiply that number with popped value and add it to the answer. This is done because we want the minimum cost and we can find that by finding the minimum neighbor value.
            while (stack.peek() <= a) {
                int mid = stack.pop();
                ans += mid * Math.min(stack.peek(), a);
            }
            //We again push the array element into the stack
            stack.push(a);
        }
        //While stack size is greater than 2, we will add the product of the top two elements at a time
        while (stack.size() > 2) {
            ans += stack.pop() * stack.peek();
        }
        return ans;
    }
}
