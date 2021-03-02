class Solution {
    public int countSquares(int[][] matrix) {
        //Answer will contain the maximum order that we can get
        int ans=0;
        //This will be our final answer
        int count=0;
        
        //Looping through the matrix and updating matrix value 
        // where the value at a position indicates that the number is the order
        //of square submatrix that can be found there
        for(int i=1;i<matrix.length;i++){
            for(int j=1;j<matrix[0].length;j++){
                if(matrix[i][j]!=0){
                    matrix[i][j]= Math.min(matrix[i][j-1], Math.min(matrix[i-1][j-1], matrix[i-1][j])) +1;
                    ans= Math.max(ans, matrix[i][j]);
                }            
            }
        }
        //This array will contain the number of order 0 matrices, number of order of 1 matrices and so on
        int[] matrices= new int[ans+1];
         for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                //This is because if there is a 2x2 matrix, then it will contain 1x1 matrix also. Similarly if there is 3x3 matrix, then it will have 2x2 matrix and 1x1 matrix also
                matrices[matrix[i][j]]+= matrix[i][j];             
            }
        }
        //Finding total submatrices
        for(int i=0;i<matrices.length;i++){
            count+= matrices[i];
        }
        return count;
    }
}
