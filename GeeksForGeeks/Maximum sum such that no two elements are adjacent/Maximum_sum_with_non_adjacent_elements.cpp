// * ALGORITHM ==>
// * This question is based on the principle of inclusion and exclusion.
// * We make a array 'dp' and for each number we store the maximum sum that can be formed by including that number and by excluding it.
// * For a number to be included we have to make sure that the number before must be excluded such that the rule of non-adjacency follows. So maximum sum (when number is included) that can be formed at the 'ith' number, here if we take that as 'x' and let it's index be 'idx', then max sum will be ∑(x + dp[not_included][idx - 1]). Basically we take the maximum sum which can be formed by excluding the previous number and adding it to the current number to get the maximum sum at 'ith' number.
// * For a number to be excluded, we can have both option (included as well as excluded) for the previous number. So the maximum sum that can be formed will be when 'ith' number, here if we take it as 'x' and it's index to be 'idx' then max sum will be max(dp[included][idx - 1], dp[not_included][idx - 1]). What we do here is to take the maximum of the maximum sum formed at the previous number by including and excluding it. Here we get both the option as the current number is for sure excluded.


// *  Main code
vector<vector<long long> > dp(2, vector<long long>(n));
dp[0][0] = arr[0];
dp[1][0] = 0;
for (int i = 1; i < n; i++)
{
    dp[0][i] = dp[1][i - 1] + arr[i];
    dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
}
cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';