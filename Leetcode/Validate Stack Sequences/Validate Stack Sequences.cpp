#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        //declaration of stack
        stack <int> st;
        int i = 0;
        
        //loop for validating stack sequence
        for(auto it : pushed)
        {
            //pushing into stack
            st.push(it);
            
            //while st is not empt and st's top is equal to popped[i]
            while(!st.empty() && st.top() == popped[i])
            {
                //popping element
                st.pop();
                i++;
            }
        }
        
        //returning 
        return st.empty();
    }
};
