#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<algorithm>
#include<string>
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

// * ALGORITHM =>
// * This is also unbounded knapsack, in which we can pick up any item any number of times, possibly 0
// * Also this question becomes very similar to coin change permutation.
// * To this we run a nested for loop. Outer for loop to traverse in the 'items' array and the inner for loop to traverse in the 'dp' array
// * This is done to generate different combinations.
// * For each traversal we store the maximum value formed at each weight
// * Each index stores the maximum value which we can achieve by collecting the items.
// * Hence at the end printing the index 'k', gives the maximum value which we can make out of 'n' items.
// * At index 0, we store 0 as the maximum value which can be achieved in bag of weight 0 is 0.




// * Driver code + main code
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int n, k;
        cin >> n >> k;
        vi v(n), dp(k + 1, 0);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        for(int l = 0; l < n; l++){     // * for loop to generate different combinations
            for(int j = 1; j <= k; j++){
                if(j >= v[l]){
                    dp[j] = max(dp[j], dp[j - v[l]] + v[l]);
                }
            }
        }
        cout << dp[k] << '\n';
    }
}