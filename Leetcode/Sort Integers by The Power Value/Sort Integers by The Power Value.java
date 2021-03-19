/*
The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

Return the k-th integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.


*/


class Solution {
    public int getKth(int lo, int hi, int k) {
        int len = hi - lo + 1;
        // 2d arr - [0] is x, [1] is x's power value
        int[][] arr = new int[len][2];
        for (int i = 0; i < len; i++) {
            arr[i][0] = lo + i;
            arr[i][1] = transform(lo + i);
        }
        
        // sort by index [1] which is x's power value
        Arrays.sort(arr, (a,b) -> Integer.compare(a[1], b[1]));

        // Here k-1 because of 0 indexing
        return arr[k-1][0];
    }
    
    public int transform(int x) {
        int temp = x;
        int count = 0;
        while (temp != 1) {
            temp = reduce(temp);
            count++;
        }
        // return power of x    
        return count;
    }
    
    // if x is even then x = x / 2
    // if x is odd then x = 3 * x + 1
    public int reduce(int x) {
        if (x % 2 == 0) x /= 2;
        else x = 3 * x + 1;
        return x;        
    }
}