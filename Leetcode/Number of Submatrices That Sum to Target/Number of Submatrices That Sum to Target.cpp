#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
  {
      //declaring variables
      int ans = 0;
      int col = matrix[0].size(); //no. of columns
      int row = matrix.size();  // no of rows
      
      //loop for taking sum of rows
      for(int i = 0; i < row; i++)
      {
         for(int j = 1; j < col; j++)
         {
            matrix[i][j] += matrix[i][j - 1];
         }
      }
      
      //declaration of map
      unordered_map <int, int> m;
      
      //loop for forming required map
      for(int i = 0; i < col; i++)
      {
         for(int j = i; j < col; j++)
         {
            //clearing the map
            m.clear();
            m[0] = 1;
            int sum = 0;
             
             //loop for calculating number of submtrices that sum to target
            for(int k = 0; k < row; k++)
            {
               int current = matrix[k][j];
               if(i - 1 >= 0)current -= matrix[k][i - 1];
               sum += current;
               ans += m[target - sum];
               m[-sum]++;
            }
         }
      }
      
      //returning number of submtrices that sum to target
      return ans;
   }
};