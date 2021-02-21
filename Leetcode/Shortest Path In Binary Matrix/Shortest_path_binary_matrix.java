class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        //8 possible directions
        int[][] dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        //lenght and width of matrix
        int n = grid.length;
        
        //if both corners are blocked then simply return -1
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        
        int distance = 0;
        
        //queue because we want to apply bfs
        Queue<int[]> q = new LinkedList<int[]>();
        
        //to keep the track of visited co-ordinates(indices)
        boolean[][] visited = new boolean[n][n];
        
        //add first co-ordinate (0,0) to queue
        q.add(new int[]{0,0});
        
        //mark (0,0) visited
        visited[0][0] = true;
        
        //while queue is not empty calculate size of queue and remove all the co-ordinates present in a queue and add eligible co-ordinates
        while(!q.isEmpty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                int[] current = q.remove();
                
                //we reached at co-ordinate (n-1,n-1) then return distance + 1
                if(current[0] == n - 1 && current[1] == n - 1){
                    return distance + 1;
                }
                
                //otherwise check for all the 8 directions using disr array
                for(int j = 0; j < 8; j++){
                    int nextX = current[0] + dir[j][0];
                    int nextY = current[1] + dir[j][1];
                    
                    //if possible next co-ordinates are in the range of matrix and it is not blocked and it is not visited then add it to the queue and mark visited as true
                    if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && grid[nextX][nextY] != 1 && !visited[nextX][nextY]){
                        q.add(new int[]{nextX,nextY});
                        visited[nextX][nextY] = true;
                    }
                }
            }
            
            //after every level increment distance by 1
            distance++;
        }
        
        //if loop is not breaked then it means that path is not found so return -1
        return -1;
    }
}
