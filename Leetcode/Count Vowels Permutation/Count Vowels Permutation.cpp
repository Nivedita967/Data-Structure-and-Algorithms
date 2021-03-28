#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countVowelPermutation(int n) 
  {
        //returning 5 if n is equal to 1 
        if(n==1)
        {
            return 5;
        }
      
        //variable declaration
        long a=1,e=1,i=1,o=1,u=1,m=1000000007;
      
        //loop for finding vowel permutations 
        for(int ii=1;ii<n;ii++)
        {
            long na=(e+i+u)%m, ne=(a+i)%m, ni=(e+o)%m, no=i, nu=(i+o)%m;
            a=na,e=ne,i=ni,o=no,u=nu;
        }
      
        //returning the count
        return (a+e+i+o+u)%m;
    }
};