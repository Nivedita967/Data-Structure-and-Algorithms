//Problem:https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

//Approach:The idea is binary search the answer from [1, m×n].
//For each candidate answer t, count how many numbers are less than / less or equal than t:
//Set a pointer p at the bottom left of the multiplication table, for each column, move up the pointer until the number < t,

class Solution {
public:
    int lessOrEqualThan(int m, int n, int t) {
        // return p:
        // there are p numbers <= t
        int count = 0;
        int row = m;
        for (int col = 1; col <= n; col++) {
            while (col * row > t) row--;
            count += row;
        }
        return count;
    }
    int lessThan(int m, int n, int t) {
        // return p:
        // there are p numbers < t
        int count = 0;
        int row = m;
        for (int col = 1; col <= n; col++) {
            while (col * row >= t) row--;
            count += row;
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {

        int a = 1;
        int b = m * n;
        
        // binary search the answer
        while (a <= b) {
            int mid = a + b >> 1;
            int count1 = lessThan(m, n, mid);
            int count2 = lessOrEqualThan(m, n, mid);
            if (count1 >= k) {
                b = mid - 1;
            } else if (count2 < k) {
                a = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
