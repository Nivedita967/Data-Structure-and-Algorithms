#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int firstMissingPositive(vector<int>& A) 
   {
        // taking size of A
         int n=A.size();
       
       //if n is empty return 1
         if(!n)
         {
             return 1;
         }
       
       //loop for swapping in sorted way
        for(int i=0;i<n;i++)
        {
            while(A[i]>0 and A[i]<=n and A[A[i]-1]!=A[i])
            {
                swap(A[A[i]-1],A[i]);
            }
        }
       
       //loop for finding smallest missing positive number
         for(int i=0;i<n;i++)
         {
             if(A[i]!=i+1) 
             { 
                 return i+1;
             }
         }
        return n+1;
    }
};