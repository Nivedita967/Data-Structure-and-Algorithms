#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int minFallingPathSum(vector<vector<int>>& arr) 
   {
    //calculating sizes of the vector and row   
    int n=arr.size(),m=arr[0].size();
       
    //loop for calculating failling path sum   
    for(int i=1;i<n;i++)
    {
      //variable declaration  
      int i1,s1=INT_MAX,i2,s2=INT_MAX;
        
        //loops for making falling paths
        for(int j=0;j<m;j++)
        {
            if(arr[i-1][j]<s1)
            {
                i1=j;
                s1=arr[i-1][j];
            }
        }
         for(int j=0;j<m;j++)
        {
            if(arr[i-1][j]<s2&&j!=i1)
            {
                i2=j;
                s2=arr[i-1][j];
            }
        }
         for(int j=0;j<m;j++)
        {
            if(i1!=j)
                arr[i][j]=arr[i][j]+s1;
            else
                arr[i][j]=arr[i][j]+s2;
        }
       
    }
     
    //variable for minimum falling path sum   
    int res=INT_MAX;
       
    //loop for finding minimum    
    for(int i=0;i<m;i++)
        res=min(res,arr[n-1][i]);
       
    //returning the required minimum falling sum   
    return res;
}
};