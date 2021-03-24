//Problem:https://leetcode.com/problems/scramble-string/description/
/*
 * Recursive Approach or TopDown Approach
 *
 * There are n-1 ways to split the string into 2 parts L, R where L is the length of s1
 * For Eg:
 *   s1 = "XY"   s2 = "YX"
 *
 * Partition s1 at 1
 *            XY
 *             |
 *          ---------
 *         |         |
 *         X         Y
 * 2 ways to merge the stirng
 *       . without swaping - XY
 *       . with swapping - YX
 *  It is seen from above that s1 and s2 are scrambled.
 */

// DP table to store the result of subproblems ie.., whether the subproblems
// s2 is scramble string of s1 or not.
std::unordered_map<string, bool> dp;

bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) {
        // Both are different sizes, then s2 can't be scramble of s1
        return false;
    }
    // Check if both the strings are equal
    if (s1 == s2) {
        // Both strings are equal i.e.., s2 is a scramble stirng of s1
        return true;
    }
    // Initializing the key key with s1 and s2 with * as differentiator
    string key = s1 + "*" + s2;
    // Check if the subproblem is already evaluated
    if (dp.count(key) == 1) {
        // Subproblem is already evaluated
        return dp[key];
    }

    int n = s1.length();
    int res = false;

    // Partition the string, As both the strings of equal length
    for (int i = 1; i < s1.length(); i++) {
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) {
            res = true;
            break;
        }
        if (isScramble(s1.substr(0, i), s2.substr(n - i, i)) &&
            isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) {
            res = true;
            break;
        }
    }

    dp[key] = res;
    return res;
}
