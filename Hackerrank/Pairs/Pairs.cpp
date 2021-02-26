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

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

// * ALGORITHM =>
// * For every element 'N' we need to find that either (N + k) or (N - k). If either of them exits, then we can say that we have found a pair.
// * It can be done in O(n) complexity with the help of hashmap or set (both unordered) which enables us for a O(1) lookup time.
// * We store each elements in a map and traverse the map searching for any of the above element (N + k) or (N - k).
// * Whenever for any number in the map, we find an element satisfying any of the above relation, we increment the count by 1 and then print it after the traversal of the map is over.

// * Driver Code + main code
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, element, count = 0;
    cin >> n >> k;
    unordered_map<int, int> my_map;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        my_map[element] += 1; // * Storing elements in the map
    }
    for (auto x : my_map)
    { // * Map traversal
        if (my_map.count(x.first - k) > 0)
        {
            count++; // * Incrementing count whenever we find the suitable element.
        }
    }
    cout << count << '\n'; // * Printing the variable count
}