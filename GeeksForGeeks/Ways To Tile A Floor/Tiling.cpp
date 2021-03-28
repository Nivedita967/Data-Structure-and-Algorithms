// * Algorithm ==>
// * Approach used : Dynamic Programming

// *    Test cases handled explicitly:
// *    Case 1: if n == 1 , only 1 configuration of tile is possible
// *    Case 2: if n == 2 , only 2 configurations are possible
// *    Case 3: if n > 2, then we got 2 possible subcases:
// *        Subcase 1: if we place lengthwise, call dp[i-2];
// *        Subcase 2: if we place width wise, call dp[i-1];

// *    At last return, dp[n] for a number of ways.

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

long long numberOfWays(long long n)
{
    int N = 1000000007;
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 2] % N) + (dp[i - 1] % N) % N);
    }
    return dp[n] % N;
}

int main()
{
    long long n;
    cin >> n;
    cout << numberOfWays(n) << endl;
}
