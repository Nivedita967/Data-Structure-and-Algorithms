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

// * Algorithm
// * In this we initialise both Alice’s and Bob’s score with 0 .
// * Then we compare for each element of the array with 2 different subcases :
// * Subcase 1: if a[i] > b[i] then Alice score will increment
// * Subcase 2: if b[i] > a[i] then Bob’s score will increment

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie();

    int a = 0, b = 0, element;
    vi v(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }

    // * Following the above subcases explained in the algorithm
    for (int i = 0; i < 3; i++)
    {
        cin >> element;
        if (element > v[i])
            b++;
        else if (v[i] > element)
            a++;
    }

    // * printing theory final scores and the winner
    cout << a << " " << b << '\n';
}
