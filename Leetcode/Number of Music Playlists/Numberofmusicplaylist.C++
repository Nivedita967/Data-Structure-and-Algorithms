
//C++ Program for Number of Music Playlists using dynamic programming
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        //initializing mod to 1e9+7
        const long long mod = 1e9 + 7; 
        vector<vector<long long>> dp(L+1, vector<long long>(N+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<=L;i++){
            for(int j=1;j<=N;j++){
                //storing the values to dp and finding mod
                dp[i][j] = j*dp[i-1][j-1] + max(0,j-K)*dp[i-1][j];
                dp[i][j] %= mod;
            }
        }
        //return answer
        return dp[L][N];
    }
};

