/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*/

class Solution {
public:
    int board[20][20];
    vector<vector<string>> ans;
    vector<string> tmp;
    
    void constructboard(int n) {
        string s = "";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j]) s += "Q";
                else s += ".";
            }
            tmp.push_back(s);
            s = "";
        }
        ans.push_back(tmp);
        tmp.clear();
    }
    
    // Backtracking algorithms usually contain this isSafe function which checks some condition required to be checked in the problem. 
    // In this problem, for any configuration, we check if any queen crosses another queen and return false for that configuration. Else it returns true.
    bool isSafe2(int row, int col, int n) {
        for(int i = 0; i < row; i++) {
            if(board[i][col]) return false;
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j]) return false;
        }
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(board[i][j]) return false;
        } 
        return true;
    }

    // This function calls itself recursively to try out different configurations of placement of queens on the board.
    bool solve2(int row, int n) {
        if(row == n) {
            constructboard(n);
            return false;
        }
        for(int i = 0; i < n; i++) {
            if(isSafe2(row, i, n)) {
                board[row][i] = 1;
                if(solve2(row + 1, n)) return true;
                board[row][i] = 0;
            }
        }
        return false;
    }
    
    // Super naive solution - n ^ 2 C n configurations
    // We generate all possible configurations of 0 to n - 1. Then we iterate through the permutationsto check if queens don't capture
    // Backtracking solution - Backtrack when we think the recursion tree is going to lead to a solution
    vector<vector<string>> solveNQueens(int n) {
        bool val = solve2(0, n);
        return ans;
    }
};
