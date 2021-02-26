#include<math.h>

class Solution {
public:
    bool isPowerOfThree(int n)
    { 
        // checking for specific values of n 
         if(n==1 || n==3 || n==9 || n==27)
          {
              //returning true as n will be power of three
              return true;
          } 

        //loop for all other possible values of n   
        for(int i=0;i<=sqrt(n);i++) 
        {
            //checking the required condition 
            if(pow(3,i)==n)
            {
                //returning true as n will be power of three
                return true;
            }
        }
         
        //returning false when n will not be any power of three
        return false;
    }   
};
