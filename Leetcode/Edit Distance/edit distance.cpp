class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> DP(word1.size() + 1, vector<int>(word2.size() + 1, 0)); // +1 on row and collumn because of
		// null string. Logic explained below.
        for (int i{1}; i <= word2.size(); i++) { // See logic below.
            DP[0][i] = i;
        }
        for (int i{1}; i <= word1.size(); i++) {
            DP[i][0] = i; // If word 2 is empty (null string), this is the amount of inserts
        } // at each character length you'd need to make. For instance, if text1 is "abc"
        // and text2 is "". Then it would take 3 inserts to go from "" to abc

        for (int i{1}; i <= word1.size(); i++) {
            for (int j{1}; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {// Nothing needs to be editted, since character is the same.
                        DP[i][j] = DP[i - 1][j - 1]; //Hence, take previous edit distance
                    } else { // Something either needs to be deleted or replaced
                    DP[i][j] = min({DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]}) + 1;
                } // If we delete a letter of i, we move up a row. If we replace a letter of i
            } // we look at the previous edit distance (which is how many edits
        // we needed to get to the replaced character). We add 1 since we've made an edit.
        }
        return DP.back().back();
    }
};