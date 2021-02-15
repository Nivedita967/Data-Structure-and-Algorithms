class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        # Append a balloon painted with `1` in the head, and a balloon painted with `1` in the tail:
        nums = [1] + nums + [1]
        # current balloons (with two `vitural` ballons)
        n = len(nums)
        # dp[i][j]: the maximum coins we can collect by bursting balloons from index `i` to index `j`
        dp = [[0 for _ in range(n)] for _ in range(n)]

        # compute dp[i][j]
        def cal(i, j):
            # memory
            if dp[i][j]:
                return dp[i][j]
            # Meaningless case. Just return 0. 
            elif i > j:
                return dp[i][j]
            else:
                coins_max = 0
                # loop through (j+1-i) possible positions for the last balloon
                for k in range(i, j + 1):
                    left = nums[i-1]
                    right = nums[j+1]
                    coins_k_max = cal(i, k - 1) + left * nums[k] * right + cal(k + 1, j)
                    coins_max = max(coins_max, coins_k_max)
                # update the memory
                dp[i][j] = coins_max
                return dp[i][j]
        # compute dp[1][n-2]
        return cal(1, n - 2)
