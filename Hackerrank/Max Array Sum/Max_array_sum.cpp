// * ALGORITHM ==>
// * Here we require the maximum sum of non adjacent elements .
// * In this we will have to store two values at each point of time :
// * Value 1: When last element was included;
// * Value 2: When last element was excluded;
// * If at the end we get maxsum < 0 , then we make maxsum = 0 , as we can have empty subsets of array.

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

    int n, _max = 0;
    cin >> n;
    vi v(n);
    vvi dp(2, vi(n, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // * Base Case
    dp[0][0] = 0;
    dp[1][0] = v[0];
    
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
        dp[1][i] = v[i] + dp[0][i - 1];
    }

    // * Checking if the max sum is negative, then we put max sum = 0, as we can return empty subset
    max(dp[0][n - 1], dp[1][n - 1]) < 0 ? _max = 0 : _max = max(dp[0][n - 1], dp[1][n - 1]);

    // * Returning maxsum;
    cout << _max << '\n';
}
