// Given two positive integers n and k.
// A factor of an integer n is defined as an integer i where n % i == 0.
// Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

int kthFactor(int n, int k){
    int i, index;
    index = 0;
    // Iterating from 1 to n in ascending order.
    for(i=1; i<=n; i++) {
        // If the factor number is equal to k then return i (i is the required factor).
        if(n%i == 0)
            index++;
        if(index == k)
            return i;
    }
    //n has less than k factors.
    return -1;
}