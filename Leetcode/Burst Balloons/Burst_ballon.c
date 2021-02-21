
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int max(int **dp, int *nums, int low, int high)
{
    if (low > high)
        return 0;

    if (dp[low][high] != -1)
        return dp[low][high];
    
    int j;
    //finding the left and right using recursion
    dp[low][high] = 0;
    for (j = low; j <= high; j++) {
        int left = max(dp, nums, low, j - 1);
        int right = max(dp, nums, j + 1, high);
        int curr = nums[low - 1] * nums[j] * nums[high + 1] + left + right;
        dp[low][high] = MAX(dp[low][high], curr);
    }
    //returning the result
    return dp[low][high];
}

int maxCoins(int* nums, int N)
{
    //Initialising dp and nums1
    int *nums1 = malloc(sizeof(int) * (N + 2));
    int **dp = malloc(sizeof(int *) * (N + 2));
    int i, j;
    
    // add 1 before and after nums
    nums1[0] = 1;
    for (i = 0; i < N; i++) {
        nums1[i + 1] = nums[i];
    }
    nums1[N + 1] = 1;
    
    for (i = 0; i < (N + 2); i++) {
        dp[i] = malloc((N + 2) * sizeof(int));
        for (j = 0; j < (N + 2); j++) {
            dp[i][j] = -1;
        }
    }
    //calculating the max
    return max(dp, nums1, 1, N);
}

