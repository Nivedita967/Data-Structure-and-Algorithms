#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<long long> vll;

// * ALGORITHM =>
// * To do this question we need to generate all the possible combinations of numbers that will lead to the formation of the required target.
// * To do this we use nested loop, outer loop is to traverse of the array of numbers & inner loop is to traverse on the 'dp' array.
// * dp[0] = 1, because we can do the payment of amount '0' by paying nothing which counts as 1 way.
// * We travel the number's array using the outer loop so that we can form a fixed pattern of numbers, like the number preceding the other number in the number array will always come before, in any of the combinations which will be counted and stored in the 'dp' array. This method will ignore the permutations as the number's position is fixed.




// * Driver Code + main code
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vll v(m), dp(n + 1, 0);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }
    dp[0] = 1;      // * Stored 1 at dp[0]
    for(int i = 0; i < m; i++){     // * Loops to generate all the possible combinations upto 'n'
        for(int j = 1; j <= n; j++){
            if(j >= v[i]){
                dp[j] += dp[j - v[i]];
            }
        }
    }
    cout << dp[n] << '\n';      // * Then we print the dp[n] to get the desired results. 
}