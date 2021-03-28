
// Program to find Minimum Difficulty of a Job Schedule
class Solution {
public:
    int minDifficulty(vector<int>& jobs, int d) {
        //finding size of vector
        int size = jobs.size();
        if(size < d) return -1;
        int dp[d+1][size+1];
        memset(dp, 0, sizeof(dp));
        
        for(int j = 1, stop = size-(d-1), max_ = 0; j <= stop; ++j) {  
            // 1st day cost is always max of all included jobs.
            max_ = max(max_, jobs[j-1]);

            //storing max in dp
            dp[1][j] = max_;
        }
        
        for(int i = 2; i <= d; ++i) {
            for(int j = i, stop = size-(d-i); j <= stop; ++j) {
                //store the int max in dp
                dp[i][j] = INT32_MAX;
                for(int k = j, max_ = 0; k >= i; --k) { 
                    max_ = max(max_, jobs[k-1]);

                    dp[i][j] = min(dp[i][j], max_ + dp[i-1][k-1]);
                }
            }
        }
        //return the answer
        return dp[d][size];
        
    }
};

