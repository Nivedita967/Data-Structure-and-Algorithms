#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) 
    {
         //Decalration of variable
        int res= 0;

        //Calculating length of row and column
		int m = mat.size();
		int n = mat[0].size();
		
        // updating the matrix based on if we found 0 or 1
		for (int row = 1; row < m; row++)
         {
			for (int col = 0; col < n; col++) 
            {
                //If it is 1, then we will update it to its prev row value+1, otherwise 0
				mat[row][col] = mat[row][col] == 1 ? mat[row - 1][col] + 1 : 0;
			}
		}
		
        //adding it to res if a value is not zero
		for (int row = 0; row < m; row++)
         {
			for (int col = 0; col < n; col++) 
            {
                //checking every column if there are more 1's
				if (mat[row][col] != 0) 
                {
					int Min = mat[row][col];
					res+= Min;
					for (int k = col + 1; k < n && mat[row][k] != 0; k++) 
                    {
						Min = min (Min, mat[row][k]);
						res+= Min;
					}
				}
			}
		}
		
        //returning res
		return res;
    }
};