class Solution {
    public int numOfWays(int n) {
        //For each row, we can have either same color on sides or different color on sides
        //Here,a is number of RYB, b is number of RYR;
        long count = 1, a = 6, b = 6, mod = 1_000_000_000 + 7;
        //For each row having RYB, the next row can have 4 possibilties, 2 of type RYB and 2 of type RYR
        //For each row having RYR, the next row can have 5 possibilities, 2 of type RYB and 3 of type RYR
        while (count++ < n) {
            long na = a * 2 + b * 2,  nb = a * 2 + b * 3;
            a = na % mod;
            b = nb % mod;
        }
        //Returning final answer
        return (int) ((a + b) % mod);
    }
}
