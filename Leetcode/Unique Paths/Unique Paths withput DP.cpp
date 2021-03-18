#include <bits/stdc++.h>
using namespace std;
/*
The code utilises the similarity of the problem to pascal's triangle and hence
uses nCr [N Combinations from R] formula to get the solution without the use of DP.

Here is the Pascals Triangle:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1

The DP grid constructed containing ways to reach any point: // Any entry gives unique ways to reach that position
1 1 1 1 1     // All the way to right is 1 way as moving right is the only option, same goes for dowwn
1 2 3 4 5     // The rest of the ways are calculted from sum of the cell's top and left negighbours
1 3 6 10 15   // as those are the only cells that can reach to it.
1 4 10 20 35  //         [ X ]
1 5 15 35 70  //           ↓
->            // [ Y ] → [X+Y]

DP Grid    Pascal's Triangel
1                1

^ 1           1    1
1

^ ^ 1
^ 2         1    2    1
1

*/
class Solution {
public:
  // Efficient code to Calculate nCr Combinations
  int NcR(int n, int r) {

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
      r = n - r;

    if (r != 0) {
      while (r) {
        p *= n;
        k *= r;
        // gcd of p, k
        long long m = __gcd(p, k);

        // dividing by gcd, to simplify
        // product division by their gcd 
        // saves from the overflow
        p /= m;
        k /= m;

        n--;
        r--;
      }

      // k should be simplified to 1
      // as C(n, r) is a natural number
      // (denominator should be 1 ) .
    } else
      p = 1;

    // if our approach is correct p = ans and k =1
    return p;
  }
  int uniquePaths(int m, int n) {
    // The solution works using (m+n)C(m) [Combinations from pascal's Triangle]
    return NcR(m + n - 2, m - 1);
  }
};