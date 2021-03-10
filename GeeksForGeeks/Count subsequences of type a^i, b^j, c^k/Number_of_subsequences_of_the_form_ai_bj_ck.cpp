//*  Algorithm ==>
// *    In this algorithm we use dynamic programming approach . Here we consider three cases, 
// *    1) subsequences strictly ending with a
// *    2) subsequences strictly ending with b
// *    3) subsequences strictly ending with c
// *    for strings ending with a , at each point of time we have 2* dp[i-1](a ending) +1 possibilities
// *    for strings ending with b , at each point of time we have 2* dp[i-1](ab ending) + a possibilities
// *    for strings ending with c , at each point of time we have 2* dp[i-1](abc ending) + b possibilities
// *    at the end number of total possible subsequences are the count of abc ending strings. 


#define mod 1000000007

int fun(string &s)
{

    // * Code here
    int a, ab, abc;
    a = ab = abc = 0;

    // * for loop on stirng length
    for (int i = 0; i < s.size(); i++)
    {

        // * for a ending case
        if (s[i] == 'a')
        {
            a = ((2 * (a % mod)) % mod + 1) % mod;
        }

        // * for b ending case
        else if (s[i] == 'b')
        {
            ab = ((2 * (ab % mod)) % mod + a) % mod;
        }

        // * for c ending case
        else
        {
            abc = ((2 * (abc % mod)) % mod + ab) % mod;
        }
    }

    // * returning total possibilities
    return abc;
}