/*
A C++ program to find Square Root
Given a non-negative integer x, compute and return the square root of x.
*/


class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r) {
            int m = l + (long long) r + 1 >> 1;
            if (m <= x / m)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};

/*
Sample Input/Output
Example 1:
Input: x = 4
Output: 2

Example 2:
Input: x = 8
Output: 2
*/
