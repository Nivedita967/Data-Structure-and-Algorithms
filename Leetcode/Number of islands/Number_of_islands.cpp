#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) 
    {   
        //calclating size of the grid
        int row = grid.size();

        //checking if grid is empty
        if (row==0)
        {  return 0;}

        //calculating size of column
        int col = grid[0].size();
        
        //variable for no of islands
        int res=0;
        vector<vector<bool>> mark(row, vector<bool>(col,true));
        
        //declaration of queue
        queue<int> q_row;
        queue<int> q_col;
        
        //loop for calculation of no of islands
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                //checking the required condition
                if (grid[i][j]=='1' && mark[i][j])
                {
                    //pushing row and column number in respective queues
                    q_row.push(i);
                    q_col.push(j);

                    //making mark as false
                    mark[i][j] = false;

                    //loop for traversing in the queue until its not empty
                    while (!q_row.empty())
                    {
                        //head node
                        int ii = q_row.front();
                        int jj = q_col.front();
                        
                        //checking all the conditions for calculation of islands 
                        if (ii+1<row && grid[ii+1][jj]=='1' && mark[ii+1][jj])
                        {
                            //pushing row and column number in respective queues
                            q_row.push(ii+1);
                            q_col.push(jj);
                            mark[ii+1][jj] = false;
                        }
                        if (jj+1<col && grid[ii][jj+1]=='1' && mark[ii][jj+1])
                        {
                            //pushing row and column number in respective queues
                            q_row.push(ii);
                            q_col.push(jj+1);
                            mark[ii][jj+1] = false;
                        }
                        if (ii-1 >=0 && grid[ii-1][jj]=='1' && mark[ii-1][jj])
                        {
                            //pushing row and column number in respective queues
                            q_row.push(ii-1);
                            q_col.push(jj);
                            mark[ii-1][jj] = false;
                        }
                        if (jj-1>=0 && grid[ii][jj-1]=='1' && mark[ii][jj-1])
                        {
                            //pushing row and column number in respective queues
                            q_row.push(ii);
                            q_col.push(jj-1);
                            mark[ii][jj-1] = false;
                        }
                        
                        //deleting element from queue 
                        q_row.pop();
                        q_col.pop();
                    }
                    //incrementing result
                    res += 1;
                }
            }
        }

        //returning result 
        return res;
    }
};
