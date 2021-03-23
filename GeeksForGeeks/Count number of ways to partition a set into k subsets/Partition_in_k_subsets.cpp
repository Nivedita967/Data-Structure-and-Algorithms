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
#define INFI 10e8
#define INF 10e7

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

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie();

    //input
    ll n, k;
    cin >> n >> k;
    vvll dp(k + 1, vll(n + 1, 0));

    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            // * When we have to put any number of people in exactly one group, then there is only one way, putting all of them in a single group
            if (i == 1){
                dp[i][j] = 1;
            }
            // * When the number of groups are more than the number of people, so there are 0 ways to do this. As we cannot have an empty group
            else if (i > j){
                dp[i][j] = 0;
            }
            // * When we have to put exactly 'k' persons in 'k' groups, so there is only one combination, ie to put 1 person in each group
            else if (i == j){
                dp[i][j] = 1;
            }
            // * When number of people are more than the number of groups
            else{
                dp[i][j] = (i * (dp[i][j - 1])) + dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[k][n] << '\n';
}
