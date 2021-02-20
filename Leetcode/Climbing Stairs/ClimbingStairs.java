class Solution {
    public int climbStairs(int n) {
        if(n < 4)
            return n;
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
