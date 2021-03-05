// The problem is to find max profit at the end of day 

// It is a maximisation problem. Can think of Greedy or DP.
// There's not seem to get any greedy solution.
// Tip:- Whenever you don't have proof for greedy try all combinations so ultimately recursion.
        //  Recursion will give you subproblems. Hence, Clicked in mind DP.

// Let's assumme that dp(n) will give max profit at the end of day n
// Subproblem will be dp(i) max profit at the end of day i

// Now task reduces to find max profit at the end of day i and run a loop from i=[0,n)
// But ith day has  one more state :-
    //              On the ith day, you can have stock 
    //              On the ith day, you have no stock


    // Now, let represent them by dp[i][1] and dp[i][0] respectively


// Case 1: Have stock on day i i.e. dp[i][1]
        //    select max of the one:-
        //     (i) i bought  it today
        //          dp[i][1]=dp[i-1][0]-price[i]-fee
        //     (ii) i bought on some previous day
        //          dp[i][1]=dp[i-1]

// Case 2: Don't have stock on day i i.e. dp[i][0]
            //    Select max of the one:-
            //    (i) i sold the stock today
            //     dp[i][0]=dp[i-1][1]+price[i]
            //    (ii) i sold stock on some previous day. No activity today
            //     dp[i][0]=dp[i-1][0]

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<vector<int>>dp(n+5,vector<int>(2,0));
        
        if(n<=1)
            return 0;
        
        dp[0][0]=0,dp[0][1]=-prices[0]-fee;
        
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]-prices[i]-fee,dp[i-1][1]);
        }
        
        return dp[n-1][0];
    }
};