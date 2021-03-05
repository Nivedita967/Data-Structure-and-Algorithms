class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding Window Technique
        // Base Case - if string length is 0, return 0.
        int n = s.length();
        if(n == 0) return 0;
        
        // Define a map (dictionary) to keep track to seen characters.
        map<char, int> m;
        int max_len = 0, start = 0;
        
        for(int i = 0; i < n; i++) {
            
            // If a charcter is present in the set, then change start position
            if(m.find(s[i]) != m.end() && start <= m[s[i]]) start = m[s[i]] + 1;
            
            // else find maximum of max_len and sliding window
            else max_len = max(max_len, i - start + 1);
            
            // Add the character in the set along with its position in the string
            m[s[i]] = i;
        }
        return max_len;
    }
};
