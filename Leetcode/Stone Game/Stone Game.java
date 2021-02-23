class Solution {
    public boolean stoneGame(int[] piles) {
        //We have been given that the total sum is odd to avoid tie
        //Also, the number of piles are even
        //Now we can say that there will be two sums, sum of all odd index elements
        //and sum of all even index elements. Either sum(odd)> sum(even) or 
        //sum(even)> sum(odd). They cannot be equal because the sum of all the elements will then become even.
        //Also Alex always has option to either select all the odd piles or even piles
        //Thus, Alex will always win
        return true;
    }
}
