#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   string helper(string &s,int &i)
    {
       //declaration of string
        string res ;
       
       //loop for decoding strings
        while(i<s.length() && s[i]!=']')
        {
            //if its a number
            if(isdigit(s[i]))
            {
                int k = 0;
                while(i<s.length() && isdigit(s[i]))
                {
                    k = k*10 + s[i++] - '0';
                }
                i++;
                
                //recursive call
                string r = helper(s,i);
                while(k-- >0)
                {
                    res+=r;
                }
                i++;
            }
            else
                res = res + s[i++];
        }
       
       //decoded string
        return res;
    }
    string decodeString(string s)
    {
        //variable declaration and returning decoded string via function call
        int i = 0;
        return helper(s,i);
    }
};