class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Defining the size of given array
        int size= prices.size();
        //Defining dp array. It will contain the maximum amount that can be achieved till i-1 elements
        int dp[size+1];
        //Since only one day is available, no transaction is possible
        dp[0]=0;
        //We define the minimum amount that is present till now
        int mnm= prices[0];
        //Looping through the array
        for(int i=1;i<size;i++){
            //We find the maximum amount that can be made till i-1 elements
            dp[i]= max(prices[i]- mnm, dp[i-1]);
            if(prices[i]<mnm){
                mnm= prices[i];
            }
        }
        //Returning the answer
        return dp[size-1];
    }
};
