/*Problem:https://leetcode.com/problems/number-of-music-playlists/description/

Approach:
Let dp[i][j] be the number of playlists of length i that have exactly j unique songs
Consider dp[i][j]. Last song, we either played a song for the first time or we didn't.
If we did, then we had dp[i-1][j-1] * (N-j) ways to choose it.
If we didn't, then we repeated a previous song in dp[i-1][j] * max(j-K, 0) ways
*/

int numMusicPlaylists(int N, int L, int K)
{
	static const int MOD = 1e9 + 7;
	long dp[L + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < L; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			dp[i + 1][j + 1] = dp[i][j] * (N - j) % MOD;
			if (j >= K)
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j + 1] * (j + 1 - K)) % MOD;
		}
	}
	return dp[L][N];
}
