#include<stdio.h>
#include<string.h>

// Returns total number of palindrome substring of
int CountPS(char str[], int n)
{
    // create empty 2-D matrix that counts all palindrome
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    // P[i][j] = 1 if substring str[i..j] is palindrome,
    int P[n][n];
    memset(P, 0, sizeof(P));

    // palindrome of single length
    for (int i = 0; i < n; i++)
      {  P[i][i] = 1;}

    // palindrome of length 2
    for (int i = 0; i < n - 1; i++)
     {
        if (str[i] == str[i + 1])
        {
            P[i][i + 1] = 1;
            dp[i][i + 1] = 1;
        }
    }

    //Loop for Palindromes of length more than 2.
    for (int gap = 2; gap < n; gap++)
    {
        // Pick starting point for current gap
        for (int i = 0; i < n - gap; i++)
        {
            // Setting ending point
            int j = gap + i;

            // If current string is palindrome
            if (str[i] == str[j] && P[i + 1][j - 1])
                {P[i][j] = 1;}

            // Add current palindrome substring ( + 1)
            // and rest palindrome substring (dp[i][j-1] +
            // dp[i+1][j]) remove common palindrome
            // substrings (- dp[i+1][j-1])
            if (P[i][j] == 1)
              {  dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1
                           - dp[i + 1][j - 1];}
            else
              { dp[i][j] = dp[i][j - 1] + dp[i + 1][j]
                           - dp[i + 1][j - 1];}
        }
    }
    // return total palindromic substrings
    return dp[0][n - 1];
}
