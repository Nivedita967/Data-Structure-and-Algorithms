//Problem:https://leetcode.com/problems/count-different-palindromic-subsequences/description/
int countPalindromicSubsequences(char *S)
{
	static const int MOD = 1e9 + 7;
	int N = strlen(S);
	int dp[N][N];
        //fill 2d array dp[N][N] with values zero from starting to end 
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i)
		dp[i][i] = 1;
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < N; ++j)
		{
                        //if s[i] != s[j] so [i,j] is not a palindromic string, we can get rid of either s[i] or s[j]
			if (S[i] != S[j])
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                        //calculate the number of duplicated elements
			else
			{
				int l = i + 1, r = j - 1;
				while (l < j && S[i] != S[l])
					++l;
				while (i < r && S[j] != S[r])
					--r;
				int duplicates = (l < r) ? -dp[l + 1][r - 1] : (r == l) ? 1 : 2;
				dp[i][j] = dp[i + 1][j - 1] * 2 + duplicates;
			}
                        //condition to check palindrome 
			dp[i][j] = dp[i][j] < 0 ? dp[i][j] + MOD : dp[i][j] % MOD;
		}
	}
	return dp[0][N - 1];
}
print(countPalindromicSubsequences("bccb"))
