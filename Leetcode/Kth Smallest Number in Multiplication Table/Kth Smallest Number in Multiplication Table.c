// Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?
// Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number
//  in this table.

// calulates the minimum of two int
int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

int findKthNumber(int m, int n, int k){
    // initalize ans as multiplication
     int ans = m*n;
        // initialize left pointer to 1 and right to ans
        int l = 1 ,r = ans;
        // While left pointer is less than right
        while (l <= r) {
            //  calculate the mid
            int mid  = (l+r) /2;
            int count =0;
            // add minimum of m & mid to count
            for(int i=1;i<=n;i++) {
                count += min(m,mid/i);
            }
            // we have found the Kth number
            if(count>=k) {
                ans = min(ans,mid);
                r=mid-1;
            } else {
                l = mid+1;
            }
        }
        // return the ans.
        return ans;

}
