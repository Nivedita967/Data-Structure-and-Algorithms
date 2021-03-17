// In This Code Since we need to Store Previous Heights For Total Sum so We are using the concept of dynamic Programming (dp)
#include<bits/stdc++.h>
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        // Declaring Book size()
        int n = books.size();
        // This is the syntax of vector where now every element id INT_MAX and Size = n+1
        vector<int>dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i = 1 ; i <=n ; ++i)
        {
            // Intializing Variables
            int max_width = shelf_width;
            int max_height = 0;
            for(int j = i-1 ; j >=0 ; --j)
            {  
                // If max_width is greater than or equal to width of that particular book then only will consider that 
                 if(max_width >= books[j][0])
                {
                max_width -= books[j][0];
                max_height = max(max_height , books[j][1]);
                dp[i] = min(dp[i] , dp[j] + max_height);
                }
                // otherwise move to next shelf
                else break;
            }
        }
        // returning the final height obtained
        return dp[n];
    }
};