#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
		vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
        {
            //declaration of matrix
            vector<vector<int>> sum(mat.size()+1,vector<int>(mat[0].size()+1,0));
            
            //loop for calculating sum of all elements accordingly
            for(int i=1;i<sum.size();i++)
            {
                for(int j=1;j<sum[i].size();j++)
                {
                        sum[i][j]=sum[i-1][j]-sum[i-1][j-1]+sum[i][j-1]+mat[i-1][j-1];
                }
            }
            
            //variables for size of input matrix 
            int m=mat.size();
            int n=mat[0].size();
            
            //loop for storing sum of bocks in their right position according to the question
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++) 
                {
                    int r1= max(0,i-K);
                    int c1= max(0,j-K); 
                    int r2= min(i+K,m-1); 
                    int c2= min(j+K,n-1); 
                    mat[i][j]=sum[r2+1][c2+1]-sum[r1][c2+1]-sum[r2+1][c1]+sum[r1][c1];
                }
            }
            
            //returning matrix 
            return mat;
        }
};