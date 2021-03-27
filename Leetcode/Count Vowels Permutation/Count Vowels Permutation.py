
#Problem :# https://leetcode.com/problems/count-vowels-permutation/
class Solution(object):
    def countVowelPermutation(self, n):

        counts = {vowel: 1 for vowel in "aeiou"}    # 1 permutation for each letter

        # Create a mapping from each vowel to the number of permutations ending with that vowel.
        # For each new letter, update the permutations from all previous vowels that can be followed by the new vowel.
        for _ in range(n - 1):
            new_counts = {}
            new_counts["a"] = counts["e"] + counts["i"] + counts["u"]
            new_counts["e"] = counts["a"] + counts["i"]
            new_counts["i"] = counts["e"] + counts["o"]
            new_counts["o"] = counts["i"]
            new_counts["u"] = counts["i"] + counts["o"]
            counts = new_counts

        return sum(counts.values()) % (10 ** 9 + 7)
