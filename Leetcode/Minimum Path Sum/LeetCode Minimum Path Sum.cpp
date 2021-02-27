// Here In this Logic We are Going From Right Bottom to the Top Left with
// using concept of dp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    //    In the above Line we are Intialising a 2-D vector as dp in which we are intialising all the values as 0
        
        for(int i = grid.size() - 1; i >= 0; i--){
            for(int j = grid[i].size() - 1; j >= 0; j--){
                if(i == grid.size() - 1 && j != grid[0].size() - 1)
                // This is the Case for Last Row , We can't Compare Beyond That
                    dp[i][j] = grid[i][j] + dp[i][j+1]; 
                
                else if(i != grid.size() - 1 && j == grid[0].size() - 1)
                // This is the Case for Last Column , We can't Compare Beyond That
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                
                else if(i != grid.size() - 1 && j != grid[0].size() - 1)
                // Here we are Calculating the min value from bottom and right Values
                    dp[i][j] = min(grid[i][j] + dp[i+1][j] , grid[i][j] + dp[i][j+1]);
                
                else
                    dp[i][j] = grid[i][j];
            }
        }
        
        return dp[0][0];
    }
};
