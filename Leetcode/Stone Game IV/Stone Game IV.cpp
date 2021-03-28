//Problem:https://leetcode.com/problems/stone-game-iv/description/
class Solution
{
public:
    bool winnerSquareGame(int n) 
    {
        vector<int> dp(n+1, 0);
        // dp[i] means if bob plays optimally
        // dp[i] == 1 means alice can win
        // dp[i] == 0 means alice will lose

        dp[0] = 0, dp[1] = 1;

        //Lets assume Alice loses for n=j.Thus, if at any point i,
        //Alice can remove a square number such that the remaining number is equal to j, and j is 0, then Alice can win at the point i.
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                if(dp[i - j*j] == 0)
                    dp[i] = 1;
            }
        }
        return (dp[n] == 1);
    }
};
