// Time Complexity is O(m*n) which is of the size of 2d matrix given
#include<bits/stdc++.h>
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        // Here In first Loop I have Tackled the condition for ones if present in first column
        for(int j = 0 ; j < m ; j++)
        {
            if(matrix[0][j]==1)
            {
                count++;
            }
        }
        // We Dont Want to count matrix[0][0] so will be starting from 2nd row this time
        for(int i = 1 ; i < n ; i++)
        {
            if(matrix[i][0]==1)
            {
                count++;
            }
        }
        // Now we are checking for other elements
      for(int i = 1 ; i < n ; i++)
      {
          for(int j = 1 ; j < m ; j++)
          {
              if(matrix[i][j]!=0)
              {
            matrix[i][j] = min(min(matrix[i-1][j] , matrix[i][j-1]) , matrix[i-1][j-1]) + 1;
            // Our Biggest Square Can Be Eliminated only to size = min of(top element , left element , diagonal element)+1
            // And Then Update that Element Finally which we are iterating here 
                  count+=matrix[i][j];
              }
          }
      }
        return count;
    }
};