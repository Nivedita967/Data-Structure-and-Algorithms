#Problem:https://leetcode.com/problems/k-th-smallest-prime-fraction/
class Solution(object):
    def kthSmallestPrimeFraction(self, A, K):
        def count_smaller_fractions(x):     # return number for fractions < x and largest such fraction

            count, denominator, largest = 0, 1, [0, 1]

            for numerator in range(len(A) - 1):     # for each numerator, find first denominator so fraction < x

                while denominator < len(A) and A[numerator] >= x * A[denominator]:  # fraction >= x
                    denominator += 1

                if denominator != len(A) and A[numerator] * largest[1] > largest[0] * A[denominator]:
                    largest = [A[numerator], A[denominator]]                        # new largest

                count += len(A) - denominator       # count this and all greater denominators

            return count, largest

        low, high = 0, 1.0
        while high - low > 10 ** -9:

            mid = (low + high) / 2
            count, largest = count_smaller_fractions(mid)
            if count < K:           # insufficient fractions below mid, search larger candidates
                low = mid
            else:                   # sufficient fractions below mid, search smaller candidates
                result = largest    # update largest fraction where count == K
                high = mid

        return result
