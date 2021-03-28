class Solution {
    public int countOrders(int n) {
        //Initialising mod value and answer value
        long ans = 1, mod = (long)1e9 + 7;
        //Assume we have already i - 1 pairs, now we need to insert the ith pair.
        // To insert the first element, there are i * 2 - 1 chioces of position。
        // To insert the second element, there are i * 2 chioces of position。
        // So there are (i * 2 - 1) * i * 2 permutations.
        // Considering that delivery(i) is always after of pickup(i), we need to divide 2.
        // So it's (i * 2 - 1) * i
        //Thus looping from 1 to n and updating ans
        for (int i = 1; i <= n; ++i)
            ans = ans * (i * 2 - 1) * i % mod;
        //Returning ans
        return (int)ans;
    }
}
