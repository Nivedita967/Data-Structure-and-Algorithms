class Solution:
    uniquePathsMap = {}
    def uniquePaths(self, m: int, n: int) -> int:
        # think of (m, n) as coordinates at the beginning location. (1, 1) is the destination.
        if m == 1 or n == 1: return 1 # reaches bottom or right boundary
        if (m, n) not in self.uniquePathsMap.keys():
            # the unique paths are sum of the unique paths form the below or right cell. Cache the result.
            self.uniquePathsMap[(m, n)] = self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)
        return self.uniquePathsMap[(m, n)