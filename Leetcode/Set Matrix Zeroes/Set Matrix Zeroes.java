// Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
class Solution {
    public void setZeroes(int[][] matrix) {
      int R = matrix.length;
      int C = matrix[0].length;
      Set<Integer> rows = new HashSet<Integer>();
      Set<Integer> cols = new HashSet<Integer>();
  
      // we mark the rows and columns that are to be made zero
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          if (matrix[i][j] == 0) {
            rows.add(i);
            cols.add(j);
          }
        }
      }
  
      // Iterate over the array once again and using the rows and cols sets, update the elements.
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // if any one of the element was 0 then make evry other element of row or column 0
          if (rows.contains(i) || cols.contains(j)) {
            matrix[i][j] = 0;
          }
        }
      }
    }
  }