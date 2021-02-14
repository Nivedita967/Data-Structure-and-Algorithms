class Solution:
    def countPrimes(self, n: int) -> int:
        out = list()
        sieve = [True] * (n)
        for p in range(2, n):
            if (sieve[p]):
                out.append(p)
                for i in range(p, n, p):
                    sieve[i] = False
        return len(out)
