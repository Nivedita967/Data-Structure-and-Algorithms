class Solution {
    public void rotate(int[][] matrix) {
        //transpose of given matrix
        for(int i=0; i<matrix.length; i++){
            for(int j=i; j<matrix.length; j++){
                int temp= matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i]= temp;
            }
        }
        int k;
        for(int i=0; i<matrix.length; i++){
            k=matrix.length-1;
            for(int j=0; j<k; j++){
                int temp= matrix[i][j];
                matrix[i][j]= matrix[i][k];
                matrix[i][k]= temp;
                k--;
            }
        }
    }
}