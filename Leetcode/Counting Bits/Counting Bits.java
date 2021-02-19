class Solution {
    public int[] countBits(int num) {
        //Our dp array will contain the answer
        int[] dp= new int[num+1];
        //Base case: there are no 1 bits in 0
        dp[0]=0;
        //Looping from 1 to our input num
        for(int i=1;i<num+1;i++){
            //If the number is even, the number of 1 bits will be same as the number's half... For example 2,4,8 all contain one 1 bits while 3,6,12 all contain two 1 bits
            if(i%2==0){
                dp[i]= dp[i/2];
            }
            //If number is odd, then it will contain an extra 1 bit then its previous number as its previous number will be even
            else{
                dp[i]= dp[i-1]+1;
            }
        }
        //Returning the ans
        return dp;
    }
}
