
//Java program for kth smallest prime number
class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        //size of array n
        int n = arr.length;
    double lo = 0.0, hi = 1.0;
    int p = 0, q = 0;
    while (true) {
        double mid = (lo + hi) / 2;
        // find the prime fraction having value less than eqaul to mid
        int count = 0;
        double maxFrac = 0.0;
        int j = 1;
        for (int i = 0; i < n - 1; i++) {
            while (j < n && arr[i] > (arr[j] * mid)) {
                j++;
            }
            //count is added to n-j
            count += (n - j);
            if (j == n)
                break;
            double currFrac = ((double)arr[i] / (double)arr[j]);
            //if currFrac > maxFrac then maxFrac = currFrac
            if (currFrac > maxFrac) {
                p = i;
                q = j;
                maxFrac = currFrac;
            }
        }
        //if count is equal to k then return new int array
        if (count == k) {
            return new int[] { arr[p], arr[q] };
        } else if (count > k) {
            //return hi as mid
            hi = mid;
        } else {
            //return lo as mid
            lo = mid;
        }
    }


    }
}

