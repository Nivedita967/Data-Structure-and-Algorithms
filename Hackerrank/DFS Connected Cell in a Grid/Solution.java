import java.io.*;
import java.util.*;

public class Solution {
    private int rows;
    private int cols;
    private int[][] grid;
    
    public Solution(int n, int m, int[][] grid) {
        this.rows = n;
        this.cols = m; 
        this.grid = grid;
    }

    /* Returns true of cell is filled AND not yet visited*/
    public boolean isValid (int x, int y) {
       //base condition is to return false whenever we reach out of bounds or whenever we encounter a cell already filled. 
        if (x < 0 ||  y < 0 ||  x >= rows ||  y >= cols ||  grid[x][y] < 1) {
            return false;
        }
        else {
            // Current cell is valid (i.e., exists in matrix, is filled and not yet visited)
            return true;
        }
    }

    /* Use DFS to return a count of the number of cells in the region connected to [x][y]. */
    public int dfs(int x, int y) {
        if (isValid(x, y) == false) {
            return 0;
        }

        int count = 1;
        grid[x][y] = -1;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newX = x + i;
                int newY = y + j;
                
                count = count + dfs(newX, newY);
            }
        }

        return count;
    }
    
    /* Find the largest region in the matrix. */
    public int solve() {
        // Stores size of current largest region
        int maxVal = 0;
        // Stores size of region currently being checked
        int tempVal = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Find the number of filled connected cells (if any) for this potential region
                tempVal = dfs(i, j);
                
                // If the current region is larger than any previously checked region, set new maxVal
                if(tempVal > maxVal) {
                    maxVal = tempVal; 
                }
            }
        }
        
        return maxVal;
    }

    /* Problem Setup */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] matrix = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {          
                matrix[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        
        Solution solution = new Solution(n, m, matrix);
        System.out.println(solution.solve());
        
    }
}