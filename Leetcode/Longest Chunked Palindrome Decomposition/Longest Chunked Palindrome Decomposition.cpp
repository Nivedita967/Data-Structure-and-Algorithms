#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestDecomposition(string text)
    {
        //declaration of variables
        int res = 0;
        int l = 0, r = text.length() - 1;
        
        //declaring stack and queue
        stack<int> s;
        queue<int> q;
        
        //loop for finding the largest possible value of k
        while (l < r)
        {
            //inserting element into stack and queue
            s.push(text[l++]);
            q.push(text[r--]);
            
            //if stack isnt empty and stacktop is equal to queuefront
            while (!s.empty() && s.top() == q.front())
            {
                //pop out the element
                q.pop();
                s.pop();
            }
            
            //if stack becomes empty
            if (s.empty())
            {
                //using ternary operator for value of res
                res += l <= r ? 2 : 1;
            }
        }
        
        //returning answer 
        return res + 1;
    }
};