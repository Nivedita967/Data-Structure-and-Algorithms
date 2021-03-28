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

// * Algorithm =>
// * In this we first store all the elements of the given ice creams in the unordered_map .
// * Then we travel on the array & try to find out the ice cream with value {money - first ice cream}
// * Basically we look for a solution of the equation => x + y = m, where 'm' is the total pooled money and 'x' and 'y' are the individual money spent by each.
// * This algorithm is used to search for an existing solution pair in O(n).



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(); 
    
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int m, n, element;
        cin >> m >> n;
        unordered_map<int, vi> my_map;

        // * Storing all the elements in unordered_map
        for(int j = 0; j < n; j++){
            cin >> element;
            my_map[element].pb(j + 1);
        }

       // * Searching for a pair with sum = money
        int f_index = -1, s_index = -1;
        for(auto money : my_map){
            int rem = m - money.first;
            if(rem == money.first){
                if(my_map[rem].size() > 1){
                    f_index = my_map[rem][0];
                    s_index = my_map[rem][1];
                    break;
                }
            }
            else{
                if(my_map.count(rem) > 0){
                    f_index = my_map[money.first][0];
                    s_index = my_map[rem][0];
                    break;
                }
            }
        }

        // * printing resultant pair
        cout << min(f_index, s_index) << " " << max(f_index, s_index) << '\n';
    }
}
