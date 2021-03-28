// * ALGORITHM ==>
// * In this algorithm we use the gap method to iterate over all possible substrings , check which of them are palindromic and which of them are longest.
// * For this we have following subcases:
// * Subcase 1: When Gap ==0 (base case)
// * Subcase 2: When Gap ==1 (base case)
// * Subcase 3: When two characters at i & jth position are same.
// * Subcase 4: When two characters at i & jth position are different.

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<long long int>> vvlli;
typedef vector<vector<bool>> vvb;

int cpsubstrings(string s)
{
    int n = (int)s.size(), count = 0;
    vvb dp(n, vb(n, false));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            // * Subcase 1;
            if (g == 0)
            {
                dp[i][j] = true;
                count++;
            }
            // * Subcase 2;
            else if (g == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                    count++;
                }
            }
            else
            {
                // * Subcase 3;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
    }
    // * Returning final count;
    return count;
}

// * Driver Code
int main()
{
    //code
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for (int k = 0; k < tc; k++)
    {
        int n;
        string s;
        cin >> n >> s;
        int count = cpsubstrings(s);
        cout << count - n << '\n';
    }
    return 0;
}
