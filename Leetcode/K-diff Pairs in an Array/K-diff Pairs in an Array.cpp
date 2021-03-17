#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        //taking size of vector
        int n=nums.size();
        
        //sorting vector
         sort(nums.begin(),nums.end());
        
        //variable declaration and initialisation
        int p=0;
        int ans=0;
        
        //loop for finding K-diff pairs in vector
        while(p<n)
        {
            int val=nums[p]+k;
            
            //perfroming binary search
            bool f=binary_search(nums.begin()+p+1,nums.end(),val);
            
            //if its true
            if(f)
            {  ans++;  }
            int x=nums[p];
            
            //calculating number of unique K-diff pairs
            while(p<n&&x==nums[p])p++;
        }
    
        //returning the answer
         return ans;
    }
};