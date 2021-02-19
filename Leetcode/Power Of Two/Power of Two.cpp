#include<math.h>

class Solution {
public:
    bool isPowerOfTwo(int n)
    {  
        // checking for specific values of n 
        if(n==1 || n==2 || n==4 || n==8)
        {
            //returning true as n will be power of two 
            return true;
        } 
        
        //loop for all other possible values of n 
        for(int i=0;i<=sqrt(n);i++) 
        {
            //checking the required condition 
            if(pow(2,i)==n)
            {
                //returning true as n will be power of two 
                return true;
            }
        }
        
        //returning false when n will not be any power of two
        return false;
    }   
};

