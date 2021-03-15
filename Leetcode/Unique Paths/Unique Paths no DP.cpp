#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int NcR(int n, int r) {
    long long p = 1, k = 1;
    if (n - r < r)
      r = n - r;
    if (r != 0) {
      while (r) {
        p *= n;
        k *= r;
        long long m = __gcd(p, k);
        p /= m;
        k /= m;
        n--;
        r--;
      }
    } else
      p = 1;
    return p;
  }
  int uniquePaths(int m, int n) {
    // The solution works using (m+n)C(m) [Combinations from pascal's Triangle]
    return NcR(m + n - 2, m - 1);
  }
};