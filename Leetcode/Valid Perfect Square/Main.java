class Solution {
  public boolean isPerfectSquare(int num) {
  
        if (num == 1 || num == 0)
            return true;
        long i = 1;
        long j = num / 2;
        //Binary Search
        while (i <= j) {
            long mid = (i + j) / 2;
            if ((mid * mid) == num)
                return true;
            if ((mid * mid) > num)
                j = mid-1;
            else if ((mid * mid) < num)
                i = mid+1;
        }
        return false;
    }
}
