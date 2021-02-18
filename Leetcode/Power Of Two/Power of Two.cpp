#include<math.h>

class Solution {
public:
    bool isPowerOfTwo(int n)
    {  if(n==1 || n==2 || n==4 || n==8) {return true;} 
        for(int i=0;i<=sqrt(n);i++) 
        {
            if(pow(2,i)==n)
            {
                return true;
            }
        }
        return false;
    }   
};

