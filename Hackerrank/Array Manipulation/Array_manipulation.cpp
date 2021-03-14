#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7
#define mod 1000000007

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef long long ll;
typedef long long int lli;
typedef pair<ll, ll> pll;
typedef vector<vector<long> > vvl;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli; 

// * ALGORITHM ==>
// * Basically this question uses the concept of prefix sum.
// * To do this question we perform the queries at only 2 positions ie (a) & (b + 1). 
// * At index 'a' we add 'k' and at index 'b + 1' we subtract 'k'.
// * Then we run a loop over the array when all the 'm' queries are over, calculating the prefix sum as well as the maximum of those prefix sum.
// * What happens is that, at any index 'i', whenever we calculate the prefix sum, the effect of addition of {1 - - - - i} affects the net value at i.
// * So when we add 'k' at index 'a' and calculate the prefix sum, the effect shows upto index 'b', but after 'b', ie 'b + 1', the effect nullifies, because of the addition of 'k' with '-k' which is stored at index 'b + 1'. So because of this, it affects the array the same way, as if we have performed a addition operation in the range a - b (inclusive).


//* Driver Code + main code
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, a, b, k, maximum = LONG_MIN;
    cin >> n >> m;

    vll v(n + 1, 0);

// *  Running 'm' queries   
    for(int i = 0; i < m; i++){
        cin >> a >> b >> k;
        v[a] += k;
        if(b < n){          // * Very very important 'if' condition to avoid a edge case when index 'b' is the last index of the array. So to avoid subtraction at 'b + 1', which is out of range, we use this 'if' condition.
            v[b + 1] -= k;
        }
    }

 // * Calculating Prefix sum and maximum of Prefix sum simultaneously.   
    for(int i = 1; i <= n; i++){
        v[i] += v[i - 1]; 
        maximum = max(maximum, v[i]);
    }
    cout << maximum << '\n';
}