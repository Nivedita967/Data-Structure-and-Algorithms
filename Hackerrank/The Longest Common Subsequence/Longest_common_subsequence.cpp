// * Algorithm =>
// *  a) To find the LCS of the two strings we divide strings as follows :
// * string 1 => {C1r1}, string 2 => {C2r2} 
// * Subcase 1: When C1 == C2
// *		In this case our LCS would be 1 more than LCS (remaining strings)
// *		Therefore,  dp[i][j] = dp[i + 1][j + 1] + 1;

// * Subcase 2: When C1 != C2 
// * 	In this case we can either move 1 character ahead in string one or one character ahead in string two , and our result would be the maximum LCS of both of the above options. 
// * Therefore,  dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);

// * b) To print LCS , we again move on our dp array, starting from 0 0 to n m index. 
// * In this we again check two subcases:
// * Subcase 1 : If C1 == C2  
// * This would be included in our answer array

// * Subcase 2: If C1 != C2 , 
// * We will check whether we came to this cell through i+1 or j+1 and move to that cell. 

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
    cin.tie();

    int n, m;
    cin >> n >> m;
    vi v1(n), v2(m), result;
    vvi dp(n + 1, vi(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    // * Moving on dp array and handling above cases
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (v1[i] == v2[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    // * To print LCS
    for (int i = 0, j = 0; i != n && j != m;)
    {
        if (v1[i] == v2[j])
        {
            result.pb(v1[i]);
            i++;
            j++;
        }
        else
        {
            if (dp[i][j + 1] > dp[i + 1][j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    if (v1[n - 1] == v2[m - 1])
    {
        result.pb(v1[n - 1]);
    }

    for (int i : result)
    {
        cout << i << " ";
    }
    cout << '\n';
}
