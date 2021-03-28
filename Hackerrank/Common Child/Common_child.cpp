// * ALGORITHM ==>
// * This is an indirect Application of Longest Common Subsequence
// * In this we need to tell the longest common child present.
// * Here we have two possible cases:
// * Subcase 1: When two characters at i & jth position are same.
// * Subcase 2: When two characters at i & jth position are different.

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

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int size1 = (int)s1.size(), size2 = (int)s2.size();
    vvi dp(size1 + 1, vi(size2 + 1, 0));

    // * Travelling on dp array from bottom right to top left cell
    for (int i = size1 - 1; i >= 0; i--)
    {
        for (int j = size2 - 1; j >= 0; j--)
        {
            // * Subcase 1;
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            // * Subcase 2;
            else
            {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    // * Final answer will be stored at first cell of dp array
    cout << dp[0][0] << '\n';
}
