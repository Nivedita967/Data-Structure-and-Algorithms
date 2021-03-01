#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        //declaring a vector
        vector<int> ret;

        //taking size of the grid and rows
        const int m = grid.size();
        const int n = grid[0].size();

        //loop for checking the balls
        for(int i = 0; i < n; i++)
        {
            ret.push_back(drop(0, i, m, n, grid));
        }

        //returning vector
        return ret;
    }
    
    // returns -1 if stuck, returns the final column index if the ball falls through
    int drop(int r, int c, int m, int n, vector<vector<int>>& grid) 
    {
        // check if it falls through the bottom
        if(r == m) 
        {
            return c;
        }
        
        // the ball is to right
        if(grid[r][c] == 1)
        {
            // check if it is stuck
            if(c == n - 1 || grid[r][c + 1] == -1 )
                return -1;
            else
                return drop(r + 1, c + 1, m, n, grid); 
        } 
        else
        {
            // the ball is to left
            // check if it is stuck
            if( c == 0 || grid[r][c - 1] == 1)
                return -1;
            else 
                return drop(r + 1, c - 1, m, n, grid);
        }
    }
};