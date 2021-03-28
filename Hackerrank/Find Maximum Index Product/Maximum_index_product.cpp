// * ALGORITHM ==>
// * In this we first find next greater element on the right and next greater element on the left of each of the element of my array.
// * Then managing the size/ range of possible values, we multiply the next greater on right and next greater on left and get the maximum index product out of it.

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

// * Next Greater On the Right
vll *ngetr(vll &v)
{
    int n = (int)v.size();
    stack<ll> my_stack;
    vll *right = new vll(n, 0);
    for (int i = 1; i < n; i++)
    {
        while (!my_stack.empty() && v[my_stack.top()] < v[i])
        {
            ll top = my_stack.top();
            my_stack.pop();
            right->at(top) = i;
        }
        my_stack.push(i);
    }
    return right;
}

// * Next Greater On the Left
vll *ngetl(vll &v)
{
    int n = (int)v.size();
    stack<ll> my_stack;
    vll *left = new vll(n, 0);
    for (int i = n - 1; i >= 1; i--)
    {
        while (!my_stack.empty() && v[my_stack.top()] < v[i])
        {
            ll top = my_stack.top();
            my_stack.pop();
            left->at(top) = i;
        }
        my_stack.push(i);
    }
    return left;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    ll _max = 0;
    cin >> n;
    vll v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vll *left = ngetl(v);
    vll *right = ngetr(v);

    // * Finding maximum index product out of all the products possible

    for (int i = 1; i <= n; i++)
    {
        ll idx_product = left->at(i) * right->at(i);
        _max = max(_max, idx_product);
    }
    cout << _max << '\n';
}
