class Solution {
    public int climbStairs(int n) {
//         base case for climbing stairs problem(stopping condition)
        if(n < 4) 
            return n;
        /*
It follows fibonaanic series
*/
        int a = 2,b = 3,curr = 0;
        for(int i = 4; i <= n; i++)
        {
            curr = a+b;
            a = b;
            b = curr;
        }
        return curr;
    }
}
