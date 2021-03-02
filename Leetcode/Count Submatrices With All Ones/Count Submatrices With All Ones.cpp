#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) 
    {
         //Decalration of required variable 
        int res= 0;

        //Calculating length of i and column
		int m = mat.size();
		int n = mat[0].size();
		
        // updating the matrix based on if we found 0 or 1
		for (int i = 1; i < m; i++)
         {
			for (int j = 0; j < n; j++) 
            {
                //If it is 1, then we will update it to its prev i value+1, otherwise 0
				mat[i][j] = mat[i][j] == 1 ? mat[i - 1][j] + 1 : 0;
			}
		}
		
        //adding it to res if a value is not zero
		for (int i = 0; i < m; i++)
         {
			for (int j = 0; j < n; j++) 
            {
                //checking every column if there are more 1's
				if (mat[i][j] != 0) 
                {
					int Min = mat[i][j];
					res+= Min;
					for (int k = j + 1; k < n && mat[i][k] != 0; k++) 
                    {
						Min = min (Min, mat[i][k]);
						res+= Min;
					}
				}
			}
		}
		
        //returning res
		return res;
    }
};