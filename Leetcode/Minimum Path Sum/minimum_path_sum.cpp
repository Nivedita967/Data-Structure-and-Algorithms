class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        //this problem is solved using dynamic programming approach thus we maintain a dp array with default value infinity
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        //the first row and first col would have only one choice of min value that the prev + the cost of this curr grid
        dp[0][0]=grid[0][0];
        for(int i=1;i<grid.size();i++){
            dp[i][0]= dp[i-1][0]+ grid[i][0];
        }
        for(int i=1;i<grid[0].size();i++){
            dp[0][i]= dp[0][i-1]+ grid[0][i];
        }

        //for all other cells the value could be minimum out of 
        //min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                dp[i][j]= min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        //returning dp[m-1][n-1] that is the last celld/ destination cell
        return dp[grid.size()-1][grid[0].size()-1];
    }
};