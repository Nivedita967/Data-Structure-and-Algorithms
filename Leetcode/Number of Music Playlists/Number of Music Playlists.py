# Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  
# You create a playlist so that:

# Every song is played at least once
# A song can only be played again only if K other songs have been played
# Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.



from functools import lru_cache

class Solution:
    def numMusicPlaylists(self, N, L, K):
        @lru_cache(None)
        # dp[i][j] be the number of playlists of length i that have exactly j unique songs.
        def dp(i, j):
            if i == 0:
                return +(j == 0)
                # Last song, we either played a song for the first time or we didn't. If we did, then we had dp[i - 1][j - 1] * (N - j + 1) 
                # ways to choose it. If we didn't, then we repeated a previous song in dp[i-1][j] * max(j-K, 0) ways
            ans = dp(i-1, j-1) * (N-j+1)
            ans += dp(i-1, j) * max(j-K, 0)
            return ans % (10**9+7)

        return dp(L, N)