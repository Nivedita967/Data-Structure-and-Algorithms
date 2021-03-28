// Consider n = 2, there are 2 possible cases:
// i. P2 followed by D2, and there are 3 positions to insert the pair (2n-1 in general)
// ii. P2 and D2 are separated, and there are 2 + 1 = 3 such permutation ( (n-1)(2n-1) in general)
// So P(2) = P(1) * (3 + 3) = 6
// In general:
// P(n) = P(n-1) * ( (2n-1) + (n-1)(2n-1) ) = P(n-1) * n * (2n-1)

class Solution {
public:
    int countOrders(int n) {
        long long int res = 1;
        for(int i=2; i<=n;i++)  res = (res * i * (2*i-1))%(int)(1e9+7);
        return res;
    }
};