#include<bits/stdc++.h>
using namespace std;

class Solution {
    //declaration of arrays
    int presumEven[100005];
    int presumOdd[100005];
public:
    //function
    int waysToMakeFair(vector<int>& nums)
    {
        //calculating size of the given vector
        int n = nums.size();
        
        //if vector have only 1 element return 1
        if(nums.size() == 1) return 1;
        
        //if vector have only two elements return 0
        if(nums.size() == 2) return 0;
        
        //copying the value of element at index 0 and 1 in the declared arrays of even and odd
        presumEven[0] = presumEven[1] = nums[0];
        presumOdd[0] = 0;
        presumOdd[1] = nums[1];
        
        //copying elements of odd and even indexes to their respective arrays 
        for(int i = 1; i < n; ++i) 
        {
            if(i % 2 == 1)
            {
                presumOdd[i] = presumOdd[i-1] + nums[i];
                presumEven[i] = presumEven[i-1];
                
            }
            else 
            {
                presumOdd[i] = presumOdd[i-1];
                presumEven[i] += presumEven[i-1] + nums[i];
            }
        }
        
        //declaration of variable ret
        int ret = 0;
        
        //checking if elements of even and odd indexes are same 
        if(presumEven[n-1] - nums[0] == presumOdd[n-1]) 
        {
            ret++;
        }
        
        //loop for removing element
        for(int i = 1; i < n; ++i)
        {
            // removing the current index
            int oddSum = presumOdd[i-1] + (presumEven[n-1] - presumEven[i]);
            int evenSum = presumEven[i-1] + (presumOdd[n-1] - presumOdd[i]);
            
            //checking if sum of od indexed values is equal to the sum of even indexed values 
            if(oddSum == evenSum) 
            {
                ret++;
            }
        }
        
        //returning the number of indices
        return ret;
    }
};