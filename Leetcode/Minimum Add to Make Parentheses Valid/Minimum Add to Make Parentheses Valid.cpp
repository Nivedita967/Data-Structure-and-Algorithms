#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) 
    {
        //declaration of variable
        int open = 0;
        int res = 0;
        
        //creates copy of each element in s and stores it in c
        for(char c:S)
        {
            //checking conditions
            if(c == '(')
            {
                open++;  
            }
            else
            {
                if(open == 0)
                {
                    res++;
                }
                else
                {
                    open--;
                }
            }
        }
        
        //minimum add to make parantheses valid
        res += open;
        return res;
    }
};