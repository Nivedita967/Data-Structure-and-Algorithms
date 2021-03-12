// * ALGORITHM ==>
// * This question is not a dynamic programming problem because of the constraints which are given in the question. Infact it is application of DFS algorithm in 2-D grid.
// * We just traverse the 2-D array and call our max_gold_path function on every cell which do not contain a '0'. We make four recursive calls, in four direction and maintain a base case such that it can prevent segmentation fault, making a call on visited cell and visiting a cell containing '0'.
// * We also maintain a visited 2-D matrix to mark cells visited, so they don't get visited again.

// * Solution class
class Solution
{
public:

// * Helper function to make the dfs calls
    int max_gold_path_helper(int i, int j, int r, int c, vector<vector<int>> &mine, vector<vector<bool>> &visited)
    {
        if (i < 0 || i >= r || j < 0 || j >= c || mine[i][j] == 0 || visited[i][j] == true)
        {
            return 0;
        }
        visited[i][j] = true;

        int top = max_gold_path_helper(i - 1, j, r, c, mine, visited);
        int right = max_gold_path_helper(i, j + 1, r, c, mine, visited);
        int bottom = max_gold_path_helper(i + 1, j, r, c, mine, visited);
        int left = max_gold_path_helper(i, j - 1, r, c, mine, visited);
        visited[i][j] = false;
        return mine[i][j] + max(max(top, bottom), max(left, right));
    }

// * getMaximumGold function make calls from each cell of the grid having a value ≠ 0 
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size(), maximum_gold = 0;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] != 0)
                {
                    int curr_max = max_gold_path_helper(i, j, r, c, grid, visited);
                    maximum_gold = max(maximum_gold, curr_max);             // * Only taking the maximum values
                }
            }
        }
     // * Returning the maximum value   
        return maximum_gold;
    }
};