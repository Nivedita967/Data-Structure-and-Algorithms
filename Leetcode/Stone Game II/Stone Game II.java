class Solution {
    public int stoneGameII(int[] piles) {
        //If there are no stones available
        if(piles.length==0){
            return 0;
        }
        int size= piles.length;
        //We will now store sums of elements from end to the i'th pile
        int[] sums= new int[size];
        sums[size-1]= piles[size-1];
        for(int i= size-2;i>=0;i--){
            sums[i]= sums[i+1]+ piles[i];
        }
        //We will create a dp vector which will store answer for i position of piles
        // with maximum 2*j piles
        int[][] dp= new int[size][size];
        return create(piles,sums,0,dp,1);
    }
    
    private int create(int [] piles, int [] sum, int i, int [][]dp, int M){
        //If it is end of the piles array
        if(i==piles.length)return 0; 
        
        //When the player has option to select all piles
        if(2*M>=piles.length-i)return sum[i] ; 
        
        //If it's already processed
        if(dp[i][M]!=0)return dp[i][M]; 
        
        //For 1<=X<=2*M, finding the point from where 2nd player can select minimum stones
        int min = Integer.MAX_VALUE;
        
        for(int X = 1;X<=2*M;X++){
            min = Math.min(min, create(piles,sum,i+X, dp, Math.max(M,X)));
        }
        
        //Storing optimal piles before returning
        return dp[i][M] = sum[i]-min;
    }
    
}
