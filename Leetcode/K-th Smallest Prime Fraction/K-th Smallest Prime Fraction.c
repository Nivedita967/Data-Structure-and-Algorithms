/*

You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

*/

int* kthSmallestPrimeFraction(int* A, int n, int k, int* returnSize) {
    // Dynamically allocate memory using malloc() by name ans
int* ans = (int*)malloc(2 * sizeof(int));
returnSize = 2;
// initialize lo & hi variable
long long lo = A[0], tar = A[n - 1] * A[n-2], hi = tar-2;
// Traverse till lo is less that hi
while (lo<hi)
{
            // Perform binary serach
            double min=1;
            long long mid = (lo + hi) / 2;
            int num = 0,pos=0;
            for (int i = 1; i<n; i++)
            {
                int tar1 = A[i];
                // increment pos till mid * tar1 < tar *A[pos]
                while (mid * tar1 >= tar *A[pos]) pos++;
                // add pos to num
                num += pos;
                if (pos>0 && (double)(mid * tar1 - tar * A[pos-1]) / tar / tar1<min)
                {
                    min = (double)(mid * tar1 - tar * A[pos-1]) / tar / tar1;
                    ans[0] = A[pos - 1];
                    ans[1] = tar1;
                }
            }
            // if true then move lo to 2 position ahead of mid
            if (num<k)
            lo = mid + 2;
             // else move hi to 2 position behind of mid
            else if(num>k)
            hi = mid-2;
            // if nums == k then break
            else
            break;
}
// return kth smallest prime fraction
return ans;
}