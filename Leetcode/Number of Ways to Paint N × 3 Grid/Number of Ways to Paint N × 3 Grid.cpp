#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) 
    {
        //declaring variables
        long long int a = 1, b = 1;
        int mod = 1e9 + 7;
        
        //loop for finding no of arrangements
        for(int i = 1; i < n; i++)
        {
            long long int a_ = ((2*a) + (2*b)) % mod;
            long long int b_ = ((2*a) + (3*b)) % mod;
            a = a_;
            b = b_;
        }
        // We multiply both a and b by 6 since there are:
        // 6 ways to arrange tiles s.t. first row has all three colors.
        // 6 ways to arrange tiles s.t. first row has only two distinct colors, and 
        long long int ans = (6*a + 6*b) % mod;
        
        //returning no of ways
        return ans;
    }
};