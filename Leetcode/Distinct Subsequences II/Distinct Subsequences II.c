//Problem:https://leetcode.com/problems/distinct-subsequences-ii/solution/
#include <string.h>

int distinctSubseqII(char *S)
{
	static const int MOD = 1e9 + 7;
	int dp = 1, last[26];
        //Initialize distinct Subsequences array with values - 1
	memset(last, -1, sizeof(last));
        //Loop to iterate though all letters of string 
	for (int i = 0; S[i]; ++i)
	{
		int pre_dp = dp;
		dp = (dp * 2) % MOD;
                // basically to avoid duplicate counting of the same subsequence if we see the last character as present character than we will
                // definately pick it up
		int index = S[i] - 'a';
		if (last[index] != -1)
			dp = (dp - last[index] + MOD) % MOD;
		last[index] = pre_dp;
	}
	return (dp - 1 + MOD) % MOD;
}
