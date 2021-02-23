/*Here we use Depth First Search (DFS) to solve this problem*/
class Solution 
{
    public int numIslands(char[][] grid) 
    {
        int count = 0;                          //declaration and initialization
        for(int i=0; i< grid.length; i++)       //to loop through the given 2D-grid of characters
        {
            for(int j=0; j<grid[i].length; j++)
            {
                if(grid[i][j]== '1')            //if we find a land
                {
                    count += 1;                 //increment counter variable
                    callDFS(grid,i,j);          //function calling
                }
            }
        }
        return count;				//return required number of islands
    }

    /*user-defined method to find the structure of the whole island by searching horizontally and
    vertically for all connected '1's (using DFS) */

    public void callDFS(char[][] grid, int i, int j)
    {
	//boundary check (so that we remain within the grid)
        if(i<0 || i>=grid.length || j<0 || j>=grid[i].length || grid[i][j]=='0')
            return;
        
        grid[i][j] = '0';       //change the value of visited land to 0
        
        callDFS(grid,i+1,j);    //check down (next row, same column)
        callDFS(grid,i-1,j);    //check up   (previous row, same column)
        callDFS(grid,i,j-1);    //check left (same row, previous column)
        callDFS(grid,i,j+1);    //check right(same row, next column)
    }
}