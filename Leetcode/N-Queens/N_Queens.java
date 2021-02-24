/*
AIM: to place n-queens on an n x n chessboard in such a manner that no two queens attack each other.

ATTACK POSITIONS: same row / same column / same diagonal

ALGORITHM USED : Backtracking
*/

class Solution 
{
    List<List<String>> result = new ArrayList<>(); 	//list of list that provides all possible solutions
    
    public List<List<String>> solveNQueens(int n) 
    {
        int[][] board = new int[n][n];          	//declare and initialize 2D-array 'board'
        for (int i=0; i < n; i++) 
        {
            for (int j=0; j < n; j++) 
            {
                board[i][j] = 0;                	//initialize all the elements with the value 0
            }
        }
        nQueen(board, 0, board.length);         	//call method
        return result;                          	//return required solution
    }

    private boolean nQueen(int[][] board, int row, int N) 
    {
        //Base Case
        if (row == N) 
        {
            constructBoard(board);              	//insert the obtained solution list in the list of solutions
            return false;                       	//Backtrack (to find other possible solutions,if any)
        }
        
        //Consider the given row and check in which column the Queen can be placed
        for (int j=0; j < N; j++) 
        {
            if (isSafe(board, row, j))          	//if current placement of Queen is safe (check by calling the method)
            {
                board[row][j] = 1;              	//place the Queen assuming the current position is safe
                if (nQueen(board, row + 1, N))  	//if the next Queen can also be placed safely
                    return true;
                board[row][j] = 0;              	//remove the Queen since this position is unsafe & Backtrack
            }
        }
        return false;                           	//Could not place Queen in this row
    }

    //method to check if the the current Queen's placement is safe
    private boolean isSafe(int[][] board, int row, int col) 
    {
        //check previous rows of present column
        for(int i=0;i<row;i++) 
        {
            if (board[i][col] == 1)             	//a Queen found
            {
                return false;                   	//unsafe position
            }
        }

        //check for Top Left Diagonal
        int x = row, y = col;
        while (x >= 0 && y >= 0)       
        {
            if (board[x][y] == 1)               	//a Queen found
            {
                return false;                   	//unsafe position
            }
            x--;
            y--;
        }

        //check for Top Right Diagonal
        x = row;
        y = col;
        while (x >= 0 && y < board.length) 
        {
            if (board[x][y] == 1)               	//a Queen found 
            {
                return false;                   	//unsafe position
            }
            x--;
            y++;
        } 
        return true;                            	//current position is safe
    }  

    private void constructBoard(int[][] board) 		//method for adding solution
    {
        List<String> subList = new ArrayList<>();
        for (int[] row : board)                 	//for rows of the board
        {
            StringBuilder sb = new StringBuilder();
            for (int col=0;col<row.length;col++)	//for columns in a row
            {
                if (row[col] == 0) 
                    sb.append(".");             	//empty space
                else 
                    sb.append("Q");             	//Queen placed
            }
            subList.add(sb.toString());         	//one Queen placed in this row
        }
        result.add(subList);                    	//one possible solution added
    }
}

