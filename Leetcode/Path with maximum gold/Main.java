class Solution {
    public int getMaximumGold(int[][] grid) { //here we need collect gold of all connected elements
        if(grid.length == 0) return 0;
        int maxGold = 0;
        boolean[][] visited = new boolean[grid.length][grid[0].length]; //visited array as we will not be revisiing an
        for(int i = 0;i<grid.length;i++){                       //element
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j] != 0 && !visited[i][j]){//element should not be visited or 0
                    int sum = dfs(i,j,grid,visited); //start from a point go in all directions and get the maximum path
                    maxGold = Math.max(maxGold,sum); //out of all paths with maximum sums we need to find the maximum
                }
            }
        }
        return maxGold;
    }
    private int dfs(int i,int j,int[][] grid,boolean[][] visited){
        if(i<0 || j<0 || i >= grid.length || j >= grid[0].length || visited[i][j] || grid[i][j] == 0)
            return 0; //if overflows like index in -ve or greater than length or is already visited or 0 return 0
        visited[i][j] = true;//mark as visited 
        int up = dfs(i-1,j,grid,visited); //going in all directions and returning the path with max sum 
        int down = dfs(i+1,j,grid,visited);
        int left = dfs(i,j-1,grid,visited);
        int right = dfs(i,j+1,grid,visited);
        visited[i][j] = false; //backtrack
        return Math.max(Math.max(up,Math.max(left,right)),down) + grid[i][j]; //while traversing one by one get current + maximum of
    }                                                                           // all directions
}
