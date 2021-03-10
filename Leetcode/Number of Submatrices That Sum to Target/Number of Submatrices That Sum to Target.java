class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int ans = 0;
        //Finding rows and columns length
        int row = matrix.length;
        int column = matrix[0].length + 1;
        int[][] sum = new int[row][column];
        
        //Storing prefix sum for each index along row
        for (int i = 0; i < sum.length; i++){
            for (int j = 1; j < sum[0].length; j++){
                sum[i][j] = sum[i][j - 1] + matrix[i][j - 1];
            }
        }
        
        //Looping through the columns
        for (int start = 0; start < column; start++){
            for (int end = start + 1; end < column; end++ ){
                //Initialising sum of submatrix and map
                int sumOfSubMatrix = 0;
                Map<Integer, Integer> map = new HashMap<Integer, Integer>();
                map.put(0, 1);
                //We can now simply use the prefix sum of each row to calculate the matrix sum between the "start" column and "end" column
                for(int l = 0; l < row; l++){
                    sumOfSubMatrix += sum[l][end] - sum[l][start];
                    if (map.containsKey(sumOfSubMatrix - target))
                        //Updating ans and map
                        ans += map.get(sumOfSubMatrix - target);
                    map.put(sumOfSubMatrix, map.getOrDefault(sumOfSubMatrix, 0) + 1);
                    
                }
            }
        }
        
        return ans;
        
    }
}
