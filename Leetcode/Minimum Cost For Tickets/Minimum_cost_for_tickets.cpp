#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
     {
        //vector for storing cost per day
        vector<int> dp(366, INT_MAX);
        for (int day : days)
         {    dp[day] = 0;}
        
        //setting it to 0
        dp[0] = 0;

        //loop for finding minimun cost
        for (int i = 1; i < 366; ++i) 
        {
            // dp[i] means min cost for day i
            if (dp[i] == INT_MAX)
               {  dp[i] = dp[i - 1];}
            else {
                //checking conditions by comparing 
                int cur = dp[i - 1] + costs[0];
                cur = min(cur, costs[1] + dp[max(0, i - 7)]);
                cur = min(cur, costs[2] + dp[max(0, i - 30)]);
                dp[i] = cur;
            }
        }

        //returning minimum cost for tickets
        return dp[days[days.size() - 1]];
     }
};
