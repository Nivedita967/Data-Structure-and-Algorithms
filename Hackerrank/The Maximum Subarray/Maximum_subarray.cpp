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

// * Algorithm ==>
// * If we can return a empty set, then the minimal value which can be returned is 0, because ∑(empty) = 0, ie if max subarray sum < 0, then we can return the max value = 0, but if we have to return a non-empty set, then we have to return the best, whether it is positive or negative.
// * The only difference in both codes is the initialization of the best and current best variable.

// * For empty set - We will initialize both the variables from 0, so that we can ignore the updation of a negative best value.
// * For non empty set - We will initialize both the variables with INT_MIN, so that, we can have a negative max subarray sum.

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie();

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++){
        int n, curr_best = INT_MIN, best = INT_MIN, best_subseq = 0, _max = INT_MIN;
        cin >> n;
        vi v(n);

        for (int j = 0; j < n; j++){
            cin >> v[j];
        }

        for (int j = 0; j < n; j++){
            _max = max(_max, v[j]);
            curr_best > 0 ? curr_best += v[j] : curr_best = v[j];

            if (v[j] > 0)
                best_subseq += v[j];

            if (curr_best > best)
                best = curr_best;
        }

        if (best_subseq == 0)
            best_subseq = _max;

        cout << best << " " << best_subseq << '\n';
    }
}
