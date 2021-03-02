#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

// * ALGORITHM =>
// * We have to maximise the number of toys that can be bought under the budget of 'k' money.
// * If we think logically, then we must buy the cheapest toys first so that we can buy a more toys.
// * So to do that, we just sort the input array consisting of prices of toys, and traverse it, till 'k' or the remaining amount equals 0 or become less than it.

// * Driver Code + main function
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n, k, toys = 0;
    cin >> n >> k;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if(k < 0 || k - v[i] < 0){
            break;
        }
        else{
            k -= v[i];
            toys++;
        }
    }
    cout << toys << '\n';
}