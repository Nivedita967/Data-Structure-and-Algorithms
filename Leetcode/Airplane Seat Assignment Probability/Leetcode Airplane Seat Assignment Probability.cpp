// Time Complexity = O(1)
// Space Complexity = O(1)
#include<bits/stdc++.h>
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n!=1 ? 0.5 : 1.0;
        // This Line Basically Represent As Ternary Operator. It Means if n not equal to 1 then print 0.5 else 1.0
        // Logic :-
        // Basically The Seat Available for nth person is either nth seat or 1st seat 
        // Any seat between nth seat and 1st seat is already been occupied.
        // so for every n>=2 the probability is 0.5 otherwise 1.
        
    }
};